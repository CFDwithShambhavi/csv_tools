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
class CSV_tools{
    
private:
    int row_count_with_headers;
    int row_count_without_headers;
    int column_count;
    std::vector< std::string > headers;
    std::vector< std::string > units;
    std::vector<T> header_data;
    std::vector<T> row_data;
    std::vector<std::vector<T>> csv_data;
    std::map<std::string, std::vector<T>> Data;

private:
    void initialise_memory(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator);
    
public:
    CSV_tools();
    CSV_tools(const int& rows, const int& columns);
    ~CSV_tools();

public:
    std::map<std::string, std::vector<T>>& read_Data(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator);
    
    int get_row_count_with_headers() const;
    int get_row_count_without_headers() const;
    int get_column_count() const;
    const std::vector<T>& get_data_in_row(const int& row_num);
    const std::vector<T>& get_data_under_header(const std::string& header_name);
    std::vector<std::string> get_headers() const;
    std::vector<std::string> get_units() const;
};

class scope{
    
private:
    CSV_tools<double>* ptr;
public:
    scope(CSV_tools<double>* ptr)
    :ptr(ptr)
    {
    }
    
    ~scope(){
        delete ptr;
    }
    
};

#endif /* CSV_tools_hpp */
