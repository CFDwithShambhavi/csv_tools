//
//  CSV_VectorData.cpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 3/16/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#include "CSV_tools.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

template <typename T>
CSV_VectorData<T>::CSV_VectorData(const std::string& file_name, const bool& have_headers, const bool& have_units, const char& separator)
:rowCountWithHeaders(0),
 rowCountWithoutHeaders(0),
 columnCount(0),
 fileName(file_name),
 haveHeaders(have_headers),
 haveUnits(have_units),
 separator(separator)
{
    countRowsAndColumns();
    
    headers.reserve(columnCount);
    units.reserve(columnCount);
    headerData.reserve(rowCountWithoutHeaders);
    transposeCSVData.reserve(columnCount);
    rowData.reserve(columnCount);
    csvData.reserve(rowCountWithoutHeaders);
    
}

template <typename T>
CSV_VectorData<T>::~CSV_VectorData()
{
}

template <typename T>
void CSV_VectorData<T>::countRowsAndColumns()
{
    bool traversed_one_row = false;
    std::string line;
    
    std::ifstream data(fileName);
    while(std::getline(data, line))
    {
        rowCountWithHeaders += 1;
        
        std::stringstream lineStream(line);
        std::string elements;
        
        if (!traversed_one_row)
        {
            while(std::getline(lineStream, elements, separator))
            {
                columnCount += 1;
            }
            traversed_one_row = true;
        }
    }
    
    if (haveHeaders == true & haveUnits == true){
        rowCountWithoutHeaders = rowCountWithHeaders - 2;
    }
    else if (haveHeaders == true & haveUnits == false){
        rowCountWithoutHeaders = rowCountWithHeaders - 1;
    }
    else if (haveHeaders == false & haveUnits == false){
        rowCountWithoutHeaders = rowCountWithHeaders;
    }
}

template <typename T>
void CSV_VectorData<T>::fill2DVectorMatrix()
{
    std::ifstream data(fileName);
    
    int rows_counter = 0;
    std::string line;
    while(std::getline(data, line))
    {
        std::vector<T> values;
        values.reserve(columnCount);
        
        std::stringstream lineStream(line);
        std::string elements;
        
        int cols_counter = 0;
        while(std::getline(lineStream, elements, separator))
        {
            if (rows_counter == 0 & haveHeaders == true) {
                headers.emplace_back(elements);
            }
            else if (rows_counter == 1 & haveUnits == true){
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
            csvData.emplace_back(values);
            values.clear();
        }
        rows_counter += 1;
    }
}

template <typename T>
void CSV_VectorData<T>::fill2DVectorMap()
{
    for(int i  = 0; i < columnCount; i++)
    {
        std::vector<T> col_data;
        col_data.reserve(rowCountWithoutHeaders);
        for(int j = 0; j < rowCountWithoutHeaders; j++)
        {
            col_data.emplace_back(csvData[j][i]);
        }
        Data[headers[i]] = col_data;
        col_data.clear();
    }
}

template <typename T>
const std::vector<std::vector<T>>& CSV_VectorData<T>::getVectorDataWithoutHeaders() const
{
    return csvData;
}

template <typename T>
const std::vector<std::vector<T>>& CSV_VectorData<T>::getTransposeVectorDataWithoutHeaders()
{
    if(transposeCSVData.empty())
    {
        std::vector<T> rowData;
        rowData.reserve(CSV_Reader<T>::rowCountWithoutHeaders);
        for(int i = 0; i < CSV_Reader<T>::columnCount; i++)
        {
            for(int j = 0; j < CSV_Reader<T>::rowCountWithoutHeaders; j++)
            {
                rowData.emplace_back(csvData[j][i]);
            }
            transposeCSVData.emplace_back(rowData);
            rowData.clear();
        }
    }
    return transposeCSVData;
}

template <typename T>
const std::vector<T>& CSV_VectorData<T>::getVectorDataUnderHeader(const std::string& header_name)
{
    headerData = Data[header_name];
    return headerData;
}

template <typename T>
const std::vector<T>& CSV_VectorData<T>::getVectorDataInRow(const int& row_num)
{
    rowData = csvData[row_num];
    return rowData;
}

template <typename T>
const std::vector<std::string>& CSV_VectorData<T>::getVectorHeaders() const
{
    return headers;
}

template <typename T>
const std::vector<std::string>& CSV_VectorData<T>::getVectorUnits() const
{
    return units;
}

template <typename T>
const std::map<std::string, std::vector<T>>& CSV_VectorData<T>::getVectorData() const
{
    return Data;
}

