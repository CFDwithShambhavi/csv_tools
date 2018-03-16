//
//  CSV_tools.cpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 2/26/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#include "CSV_tools.hpp"
/*

template <typename T>
CSV_ArrayData<T>::CSV_ArrayData()
:rowCountWithHeaders(0),
 rowCountWithoutHeaders(0),
 columnCount(0),
 headers(0),
 units(0),
 headerData(0),
 rowData(0),
 csvData(0),
 transposeCSVData(0)
{
}
 
template <typename T>
CSV_ArrayData<T>::CSV_ArrayData(const int& rowsWithHeaders, const int& rowsWithoutHeaders, const int& columns)
:rowCountWithHeaders(rowsWithHeaders),
 rowCountWithoutHeaders(rowsWithoutHeaders),
 columnCount(columns),
 headers(0),
 units(0),
 headerData(0),
 rowData(0),
 csvData(0),
 transposeCSVData(0)
{
     headers = new T[columnCount];
     units = new T[columnCount];
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
    delete [] transposeCSVData
}

template <typename T>
void CSV_ArrayData<T>::fill2Dmatrix()
{
    for(int i = 0; i < CSV_Reader<T>::rowCountWithoutHeaders; i++)
    {
        for(int j = 0; j < CSV_Reader<T>::columnCount; j++)
        {
            csvData[i* CSV_Reader<T>::columnCount + j] = CSV_VectorData<T>::csvData[i][j];
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
    int h_index = CSV_Reader<T>::findHeaderIndex(header_name);
    
    for(int i = 0; i < CSV_Reader<T>::rowCountWithoutHeaders; i++)
        {
            headerData[i] = CSV_VectorData<T>::csvData[i][h_index];
        }
    
    return headerData;
}
 
template <typename T>
const T* CSV_ArrayData<T>::getArrayDataInRow(const int& row_num)
{
    for(int i = 0; i < CSV_Reader<T>::columnCount; i++)
    {
        rowData[i] = CSV_VectorData<T>::csvData[row_num][i];
    }
    
    return rowData;
}
*/

