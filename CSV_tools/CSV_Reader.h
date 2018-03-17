//
//  CSV_Reader.h
//  CSV_tools
//
//  Created by Shambhavi Nandan on 3/17/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#ifndef CSV_Reader_h
#define CSV_Reader_h

#include "CSV_ArrayData.h"

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

#endif /* CSV_Reader_h */
