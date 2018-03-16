//
//  CSV_tools.hpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 2/26/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#ifndef CSV_tools_hpp
#define CSV_tools_hpp

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

template <typename T>
class CSV_Reader : public CSV_ArrayData<T>{
    
protected:
    std::string dataType;
    bool loadData;
    
protected:
    void findDataType();
    
public:
    CSV_Reader(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator);
    ~CSV_Reader();
    
public:
    void readData();
    const std::string& getDataType() const;
    const int& getRowCountWithHeaders() const;
    const int& getRowCountWithoutHeaders() const;
    const int& getColumnCount() const;
    
};

#endif /* CSV_tools_hpp */
