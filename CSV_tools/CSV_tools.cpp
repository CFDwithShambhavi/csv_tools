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

template <typename T>
CSV_tools<T>::CSV_tools()
    : row_count_with_headers(0),
    row_count_without_headers(0),
    column_count(0),
    data_type("unknown"),
    headers(NULL),
    units(NULL),
    header_data(NULL),
    row_data(NULL),
    csv_data(NULL)
    {
    }

template <typename T>
CSV_tools<T>::CSV_tools(const int& rows_without_headers, const int& columns)
{
    headers.reserve(columns);
    units.reserve(columns);
    header_data.reserve(rows_without_headers);
    row_data.reserve(columns);
    csv_data.reserve(rows_without_headers);
}

template <typename T>
CSV_tools<T>::~CSV_tools()
{
}

template <typename T>
std::string CSV_tools<T>::dataType()
{
    if(std::is_same<T, int>::value){
        data_type = "inetegr";
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
void CSV_tools<T>::initialise_memory(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator)
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

    CSV_tools(row_count_without_headers, column_count);
}


template <typename T>
const std::map<std::string, std::vector<T>>& CSV_tools<T>::read_Data(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator)
{
    initialise_memory(file_name, headers_, units_, separator);
    
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
                //std::stringstream e(elements);
                std::stringstream e;
                e << elements;
                T vals;
                e >> vals;
                values.emplace_back(vals);
            }
            cols_counter += 1;
        }
        
        if (!values.empty()) {
            csv_data.emplace_back(values);
            values.clear();
        }
        rows_counter += 1;
    }
    
    // stroing data in a map
    for(int i  = 0; i < column_count; i++){
        std::vector<T> col_data;
        col_data.reserve(row_count_without_headers);
        for(int j = 0; j < row_count_without_headers; j++){
            col_data.emplace_back(csv_data[j][i]);
        }
        Data[headers[i]] = col_data;
        col_data.clear();
    }
    return Data;
}

template <typename T>
const int& CSV_tools<T>::get_row_count_with_headers() const
{
    return row_count_with_headers;
}

template <typename T>
const int& CSV_tools<T>::get_row_count_without_headers() const
{
    return row_count_without_headers;
}


template <typename T>
const int& CSV_tools<T>::get_column_count() const
{
    return column_count;
}

template <typename T>
const std::vector<std::string>& CSV_tools<T>::get_headers() const
{
    return headers;
}

template <typename T>
const std::vector<std::string>& CSV_tools<T>::get_units() const
{
    return units;
}

template <typename T>
const std::string& CSV_tools<T>::get_data_type() const
{
    return data_type;
}

template <typename T>
const std::vector<T>& CSV_tools<T>::get_data_under_header(const std::string& header_name)
{
    header_data = Data[header_name];
    return header_data;
}

template <typename T>
const std::vector<T>& CSV_tools<T>::get_data_in_row(const int& row_num)
{
    row_data = csv_data[row_num];
    return row_data;
}
