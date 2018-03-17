//
//  CSV_Reader.cpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 3/16/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#include "CSV_Reader.h"

#include <type_traits>


template <typename T>
CSV_Reader<T>::CSV_Reader(const std::string& file_name, const bool& have_headers, const bool& have_units, const char& separator)
:CSV_ArrayData<T>::CSV_ArrayData(file_name, have_headers, have_units, separator),
 dataType("Unknown"),
 loadData(false)
{
}

template <typename T>
CSV_Reader<T>::~CSV_Reader()
{
}

template <typename T>
void CSV_Reader<T>::readData()
{
    findDataType();
    
    CSV_VectorData<T>::fill2DVectorMatrix();
    
    CSV_VectorData<T>::fill2DVectorMap();
    
    CSV_ArrayData<T>::fill2DArrayMatrix();
    
    loadData = true;
}

template <typename T>
void CSV_Reader<T>::findDataType()
{
    if(std::is_same<T, int>::value){
        dataType = "integer";
    }
    else if(std::is_same<T, double>::value){
        dataType = "double";
    }
    else if(std::is_same<T, std::string>::value){
        dataType = "std::string";
    }
    else{
        dataType = "data type can not be deduced";
    }
}

template <typename T>
const int& CSV_Reader<T>::getRowCountWithHeaders() const
{
    return CSV_VectorData<T>::rowCountWithHeaders;
}

template <typename T>
const int& CSV_Reader<T>::getRowCountWithoutHeaders() const
{
    return CSV_VectorData<T>::rowCountWithoutHeaders;
}

template <typename T>
const int& CSV_Reader<T>::getColumnCount() const
{
    return CSV_VectorData<T>::columnCount;
}

template <typename T>
const std::string& CSV_Reader<T>::getDataType() const
{
    return dataType;
}
