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
#include <tuple>
#include <map>

template <typename T>
CSV_tools<T>::CSV_tools()
    : row_count(0),
    column_count(0),
    headers(NULL),
    csv_data(NULL)
    {
    }

template <typename T>
CSV_tools<T>::~CSV_tools(){
        delete [] headers;
    }

template <typename T>
std::tuple<int, int> CSV_tools<T>::get_row_and_col_count(const std::string& file_name, const char& separator){
        
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
        
        return {row_count, column_count};
    }

template <typename T>
T CSV_tools<T>::read_data(const std::string& file_name, const char& separator) {
        
        auto [no_of_rows, no_of_cols] = get_row_and_col_count(file_name, separator);
        
        headers = new std::string[no_of_cols];
        csv_data.reserve(no_of_rows - 1);

        std::ifstream data(file_name);
        
        int rows = 0;
        std::string line;
        while(std::getline(data, line))
        {
            std::vector<std::string> values;
            values.reserve(no_of_cols);

            std::stringstream lineStream(line);
            std::string elements;
            int cols = 0;
            
            while(std::getline(lineStream, elements, separator))
            {
                if (rows == 0) {
                    headers[cols] = elements;
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
        
        std::vector<std::string> headers_;
        
        headers_.reserve(column_count);
        
        for(int i = 0; i < column_count; i++) {
            
            headers_.emplace_back(headers[i]);
            
        }
        return headers_;
    }

template <typename T>
std::vector<T> CSV_tools<T>::get_data_under_header(const std::string& header_name) const{
        
        int header_index = 0;
        for(int i = 0; i < column_count; i++) {
            if (headers[i] == header_name) {
                header_index = i;
            }
        }
    
        std::vector<T> header_data;
        header_data.reserve(row_count - 1);
        
        for(int i = 0; i < row_count - 1; i++) {
            header_data.emplace_back(atof(csv_data[i][header_index].c_str()));
        }
        return header_data;
    }
