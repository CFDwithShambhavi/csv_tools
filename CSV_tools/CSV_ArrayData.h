//
//  CSV_ArrayData.h
//  CSV_tools
//
//  Created by Shambhavi Nandan on 3/17/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#ifndef CSV_ArrayData_h
#define CSV_ArrayData_h

#include "CSV_VectorData.h"

template <typename T>
class CSV_ArrayData: public CSV_VectorData<T>{
    
private:
    int rowCountWithHeaders;
    int rowCountWithoutHeaders;
    int columnCount;
    std::string fileName;
    bool haveHeaders;
    bool haveUnits;
    char separator;
    std::string* headers;
    std::string* units;
    T* headerData;
    T* rowData;
    T* csvData;
    T* transposeCSVData;
    
protected:
    void fill2DArrayMatrix();
    int findHeaderIndex(const std::string& header_name);
    
public:
    //CSV_ArrayData();
    CSV_ArrayData(const std::string& file_name, const bool& have_headers, const bool& have_units, const char& separator);
    ~CSV_ArrayData();
    
public:
    const T* getTransposeArrayDataWithoutHeaders();
    const T* getArrayHeaders() const;
    const T* getArrayUnits() const;
    const T* getArrayDataInRow(const int& row_num);
    const T* getArrayDataUnderHeader(const std::string& header_name);
    const T* getArrayDataWithoutHeaders() const;
    
};


#endif /* CSV_ArrayData_h */
