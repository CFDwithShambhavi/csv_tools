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
    int row_count;
    int column_count;
    std::vector< std::vector<std::string> > csv_data;
    std::vector< std::string > headers;
    std::vector<T> header_data;
    std::map<std::string, T> data;
    
private:
    void initialise_memory(const std::string& file_name, const char& separator);
    
public:
    CSV_tools();
    CSV_tools(int& rows, int& columns);
    ~CSV_tools();

public:
    T read_data(const std::string& file_name, const char& separator);
    std::vector<T>& get_data_under_header(const std::string& header_name);
    
    int get_row_count() const;
    int get_column_count() const;
    std::vector<std::string> get_headers() const;
};



#endif /* CSV_tools_hpp */
