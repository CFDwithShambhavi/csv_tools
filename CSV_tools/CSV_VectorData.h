//
//  CSV_VectorData.h
//  CSV_tools
//
//  Created by Shambhavi Nandan on 3/17/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#ifndef CSV_VectorData_h
#define CSV_VectorData_h

#include <string>
#include <vector>
#include <map>

template <typename T>
class CSV_VectorData{
    
protected:
    int rowCountWithHeaders;
    int rowCountWithoutHeaders;
    int columnCount;
    std::string fileName;
    bool haveHeaders;
    bool haveUnits;
    char separator;
    std::vector<std::string> headers;
    std::vector<std::string> units;
    std::vector<T> headerData;
    std::vector<T> rowData;
    std::vector<std::vector<T>> transposeCSVData;
    std::map<std::string, std::vector<T>> Data;
    std::vector<std::vector<T>> csvData;
    
protected:
    void fill2DVectorMatrix();
    void fill2DVectorMap();
    
private:
    void countRowsAndColumns();
    
public:
    //CSV_VectorData();
    
    CSV_VectorData(const std::string& file_name, const bool& have_headers, const bool& have_units, const char& separator);
    
    ~CSV_VectorData();
    
public:
    const std::vector<std::vector<T>>& getTransposeVectorDataWithoutHeaders();
    const std::vector<std::string>& getVectorHeaders() const;
    const std::vector<std::string>& getVectorUnits() const;
    const std::map<std::string, std::vector<T>>& getVectorData() const;
    const std::vector<T>& getVectorDataInRow(const int& row_num);
    const std::vector<T>& getVectorDataUnderHeader(const std::string& header_name);
    const std::vector<std::vector<T>>& getVectorDataWithoutHeaders() const;
    
};


#endif /* CSV_VectorData_h */
