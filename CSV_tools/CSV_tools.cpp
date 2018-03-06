//
//  CSV_tools.cpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 2/26/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#include "CSV_tools.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <type_traits>
#include <array>

template <typename T>
CSV_Reader<T>::CSV_Reader()
    :read_data(false),
    row_count_with_headers(0),
    row_count_without_headers(0),
    column_count(0),
    data_type("unknown"),
    headers(NULL),
    units(NULL),
    header_vector_data(NULL),
    header_array_data(NULL),
    row_vector_data(NULL),
    row_array_data(NULL),
    csv_vector_data(NULL),
    csv_array_data(NULL),
    transpose_csv_vector_data(NULL)
    {
    }

template <typename T>
CSV_Reader<T>::~CSV_Reader()
{
    delete [] header_array_data;
    delete [] row_array_data;
    delete [] csv_array_data;
}

template <typename T>
void CSV_Reader<T>::dataType()
{
    if(std::is_same<T, int>::value){
        data_type = "integer";
    }
    else if(std::is_same<T, double>::value){
        data_type = "double";
    }
    else if(std::is_same<T, std::string>::value){
        data_type = "std::string";
    }
    else{
        data_type = "data type can not be deduced";
    }
}

template <typename T>
void CSV_Reader<T>::count_rows_and_columns(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator)
{
    bool traversed_one_row = false;
    std::string line;

    std::ifstream data(file_name);
    while(std::getline(data, line))
    {
        row_count_with_headers += 1;
        
        std::stringstream lineStream(line);
        std::string elements;
        
        if (!traversed_one_row)
        {
        while(std::getline(lineStream, elements, separator))
        {
            column_count += 1;
        }
            traversed_one_row = true;
        }
    }
    
    if (headers_ == true & units_ == true){
        row_count_without_headers = row_count_with_headers - 2;
    }
    else if (headers_ == true & units_ == false){
        row_count_without_headers = row_count_with_headers - 1;
    }
    else if (headers_ == false & units_ == false){
        row_count_without_headers = row_count_with_headers;
    }
}

template <typename T>
void CSV_Reader<T>::initialise_memory()
{
    headers.reserve(column_count);
    units.reserve(column_count);
    header_vector_data.reserve(row_count_without_headers);
    header_array_data = new T[row_count_without_headers];
    row_vector_data.reserve(column_count);
    row_array_data = new T[column_count];
    csv_vector_data.reserve(row_count_without_headers);
    csv_array_data = new T[row_count_without_headers * column_count];
    transpose_csv_vector_data.reserve(column_count);
}

template <typename T>
void CSV_Reader<T>::fill_2D_Vector(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator)
{
    std::ifstream data(file_name);
    
    int rows_counter = 0;
    std::string line;
    while(std::getline(data, line))
    {
        std::vector<T> values;
        values.reserve(column_count);
        
        std::stringstream lineStream(line);
        std::string elements;
        
        int cols_counter = 0;
        while(std::getline(lineStream, elements, separator))
        {
            if (rows_counter == 0 & headers_ == true) {
                headers.emplace_back(elements);
            }
            else if (rows_counter == 1 & units_ == true){
                units.emplace_back(elements);
            }
            else {
                std::stringstream e(elements);
                T vals;
                e >> vals;
                values.emplace_back(vals);
            }
            cols_counter += 1;
        }
        
        if (!values.empty()) {
            csv_vector_data.emplace_back(values);
            values.clear();
        }
        rows_counter += 1;
    }
}

template <typename T>
void CSV_Reader<T>::fill_2D_Vector_map()
{
    for(int i  = 0; i < column_count; i++)
    {
        std::vector<T> col_data;
        col_data.reserve(row_count_without_headers);
        for(int j = 0; j < row_count_without_headers; j++)
        {
            col_data.emplace_back(csv_vector_data[j][i]);
        }
        vector_Data[headers[i]] = col_data;
        col_data.clear();
    }
}

template <typename T>
void CSV_Reader<T>::fill_2D_Array()
{
    for(int i = 0; i < row_count_without_headers; i++)
    {
        for(int j = 0; j < column_count; j++)
        {
            csv_array_data[i* column_count + j] = csv_vector_data[i][j];
        }
    }
}

template <typename T>
void CSV_Reader<T>::read_Data(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator)
{
    dataType();
    
    count_rows_and_columns(file_name, headers_, units_, separator);
    
    initialise_memory();
    
    fill_2D_Vector(file_name, headers_, units_, separator);
    
    fill_2D_Vector_map();
    
    fill_2D_Array();
    
    read_data = true;
}

template <typename T>
const std::vector<std::vector<T>>& CSV_Reader<T>::get_VectorData_without_headers() const
{
    return csv_vector_data;
}

template <typename T>
const T* CSV_Reader<T>::get_ArrayData_without_headers() const
{
    return csv_array_data;
}

template <typename T>
const std::vector<std::vector<T>>& CSV_Reader<T>::get_transpose_VectorData_without_headers()
{
    if(transpose_csv_vector_data.empty())
    {
        std::vector<T> row_data;
        row_data.reserve(row_count_without_headers);
    for(int i = 0; i < column_count; i++)
    {
        for(int j = 0; j < row_count_without_headers; j++)
        {
            row_data.emplace_back(csv_vector_data[j][i]);
        }
        transpose_csv_vector_data.emplace_back(row_data);
        row_data.clear();
    }
    }
    return transpose_csv_vector_data;
}

template <typename T>
const std::vector<T>& CSV_Reader<T>::get_VectorData_under_header(const std::string& header_name)
{
    header_vector_data = vector_Data[header_name];
    return header_vector_data;
}

template <typename T>
const std::vector<T>& CSV_Reader<T>::get_VectorData_in_row(const int& row_num)
{
    row_vector_data = csv_vector_data[row_num];
    return row_vector_data;
}

template <typename T>
const T* CSV_Reader<T>::get_ArrayData_in_row(const int& row_num)
{
    for(int i = 0; i < column_count; i++)
    {
        row_array_data[i] = csv_vector_data[row_num][i];
    }
    
    return row_array_data;
}

template <typename T>
const int& CSV_Reader<T>::get_row_count_with_headers() const
{
    return row_count_with_headers;
}

template <typename T>
const int& CSV_Reader<T>::get_row_count_without_headers() const
{
    return row_count_without_headers;
}

template <typename T>
const int& CSV_Reader<T>::get_column_count() const
{
    return column_count;
}

template <typename T>
const std::vector<std::string>& CSV_Reader<T>::get_headers() const
{
    return headers;
}

template <typename T>
const std::vector<std::string>& CSV_Reader<T>::get_units() const
{
    return units;
}

template <typename T>
const std::string& CSV_Reader<T>::get_data_type() const
{
    return data_type;
}

template <typename T>
const std::map<std::string, std::vector<T>>& CSV_Reader<T>::get_Vector_Data() const
{
    return vector_Data;
}

