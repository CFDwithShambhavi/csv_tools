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

template <typename T>
class CSV_tools{
    
private:
    int row_count;
    int column_count;
    std::vector< std::vector<std::string> > csv_data;
    std::string* headers;
    
public:
    CSV_tools();
    ~CSV_tools();
    
private:
    std::tuple<int, int> get_row_and_col_count(const std::string& file_name, const char& separator);
    
public:
    T read_data(const std::string& file_name, const char& separator);
    int get_row_count() const;
    int get_column_count() const;
    std::vector<std::string> get_headers() const;
    std::vector<T> get_data_under_header(const std::string& header_name) const;
};



#endif /* CSV_tools_hpp */
