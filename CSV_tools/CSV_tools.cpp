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
#include <array>

template <typename T>
CSV_tools<T>::CSV_tools()
    : row_count(0),
    column_count(0),
    headers(NULL),
    header_data(NULL),
    csv_data(NULL)
    {
    }

template <typename T>
CSV_tools<T>::CSV_tools(int& rows, int& columns)
{
    headers.reserve(columns);
    header_data.reserve(rows - 1);
    csv_data.reserve(rows - 1);
}

template <typename T>
CSV_tools<T>::~CSV_tools(){
    }

template <typename T>
void CSV_tools<T>::initialise_memory(const std::string& file_name, const char& separator){
        
        std::ifstream data(file_name);
        
        bool traversed_one_row = false;
        std::string line;
        while(std::getline(data, line))
        {
            row_count += 1;
            
            std::stringstream lineStream(line);
            std::string elements;
            int cols = 0;
            
            while(std::getline(lineStream, elements, separator))
            {
                cols += 1;
                traversed_one_row = true;
                    }
            
            if (traversed_one_row)
                column_count = cols;
        }
    
    CSV_tools(row_count, column_count);
    
    }

template <typename T>
T CSV_tools<T>::read_data(const std::string& file_name, const char& separator) {
        
        initialise_memory(file_name, separator);

        std::ifstream data(file_name);
        
        int rows = 0;
        std::string line;
        while(std::getline(data, line))
        {
            std::vector<std::string> values;
            values.reserve(column_count);

            std::stringstream lineStream(line);
            std::string elements;
            int cols = 0;
            
            while(std::getline(lineStream, elements, separator))
            {
                if (rows == 0) {
                    headers.emplace_back(elements);
                }
                else {
                    values.emplace_back(elements);
                }
                cols += 1;
            }
            
            if (rows >= 1) {
            csv_data.emplace_back(values);
            values.clear();
            }
            rows += 1;
        }
        
        return 0;
    }

template <typename T>
int CSV_tools<T>::get_row_count() const{
    return row_count;
    }

template <typename T>
int CSV_tools<T>::get_column_count() const{
        return column_count;
    }

template <typename T>
std::vector<std::string> CSV_tools<T>::get_headers() const{
        return headers;
    }

template <typename T>
std::vector<T>& CSV_tools<T>::get_data_under_header(const std::string& header_name){
    
        int header_index = 0;
        for(int i = 0; i < column_count; i++) {
            if (headers[i] == header_name) {
                header_index = i;
            }
        }
        for(int i = 0; i < row_count - 1; i++) {
            header_data.emplace_back(atof(csv_data[i][header_index].c_str()));
        }
        return header_data;
    }
