//
//  CSV_ArrayData.cpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 3/16/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#include "CSV_tools.hpp"

#include <iostream>

template <typename T>
CSV_ArrayData<T>::CSV_ArrayData(const std::string& file_name, const bool& have_headers, const bool& have_units, const char& separator)
:CSV_VectorData<T>::CSV_VectorData(file_name, have_headers, have_units, separator),
 rowCountWithHeaders(CSV_VectorData<T>::rowCountWithHeaders),
 rowCountWithoutHeaders(CSV_VectorData<T>::rowCountWithoutHeaders),
 columnCount(CSV_VectorData<T>::columnCount),
 fileName(file_name),
 haveHeaders(have_headers),
 haveUnits(have_units),
 separator(separator),
 headers(0),
 units(0),
 headerData(0),
 rowData(0),
 csvData(0),
 transposeCSVData(0)
{
    headers = new std::string[columnCount];
    units = new std::string[columnCount];
    headerData = new T[rowCountWithoutHeaders];
    rowData = new T[columnCount];
    csvData = new T[rowCountWithoutHeaders * columnCount];
    transposeCSVData = new T[columnCount * rowCountWithoutHeaders];
}

template <typename T>
CSV_ArrayData<T>::~CSV_ArrayData()
{
    delete [] headers;
    delete [] units;
    delete [] headerData;
    delete [] rowData;
    delete [] csvData;
    delete [] transposeCSVData;
}

template <typename T>
int CSV_ArrayData<T>::findHeaderIndex(const std::string& header_name)
{
    int index = 0;
    for(int i = 0; i < columnCount; i++)
    {
        if(CSV_VectorData<T>::headers[i] == header_name)
        {
            index = i;
            break;
        }
    }
    return index;
}


template <typename T>
void CSV_ArrayData<T>::fill2DArrayMatrix()
{
    for(int i = 0; i < rowCountWithoutHeaders; i++)
    {
        for(int j = 0; j < columnCount; j++)
        {
            csvData[i* columnCount + j] = CSV_VectorData<T>::csvData[i][j];
        }
    }
}

template <typename T>
const T* CSV_ArrayData<T>::getArrayDataWithoutHeaders() const
{
    return csvData;
}

template <typename T>
const T* CSV_ArrayData<T>::getArrayDataUnderHeader(const std::string& header_name)
{
    int h_index = findHeaderIndex(header_name);
    
    for(int i = 0; i < rowCountWithoutHeaders; i++)
    {
        headerData[i] = CSV_VectorData<T>::csvData[i][h_index];
    }
    
    return headerData;
}

template <typename T>
const T* CSV_ArrayData<T>::getArrayDataInRow(const int& row_num)
{
    for(int i = 0; i < columnCount; i++)
    {
        rowData[i] = CSV_VectorData<T>::csvData[row_num][i];
    }
    
    return rowData;
}
