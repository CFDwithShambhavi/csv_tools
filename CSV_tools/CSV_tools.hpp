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
    std::vector<std::vector<T>> csv_data;
    std::vector<T> header_data;
    std::vector<T> row_data;
    std::map<std::string, std::vector<T>> Data;
    std::vector< std::string > units;
    std::vector< std::string > headers;

private:
    void initialise_memory(const std::string& file_name, bool headers_, bool units_, const char& separator);
    
public:
    CSV_tools();
    CSV_tools(int& rows, int& columns);
    ~CSV_tools();

public:
    std::map<std::string, std::vector<T>>& read_Data(const std::string& file_name, bool headers_, bool units_, const char& separator);
    
    int get_row_count_with_headers() const;
    int get_row_count_without_headers() const;
    int get_column_count() const;
    const std::vector<T>& get_data_in_row(int& row_num);
    const std::vector<T>& get_data_under_header(const std::string& header_name);
    std::vector<std::string> get_headers() const;
    std::vector<std::string> get_units() const;
};



#endif /* CSV_tools_hpp */
