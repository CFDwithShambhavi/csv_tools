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
#include <array>

template <typename T>
class CSV_Reader{
    
private:
    bool read_data;
    int row_count_with_headers;
    int row_count_without_headers;
    int column_count;
    std::string data_type;
    std::vector< std::string > headers;
    std::vector< std::string > units;
    std::vector<T> header_vector_data;
    T* header_array_data;
    std::vector<T> row_vector_data;
    T* row_array_data;
    std::vector<std::vector<T>> csv_vector_data;
    T* csv_array_data;
    std::vector<std::vector<T>> transpose_csv_vector_data;
    std::map<std::string, std::vector<T>> vector_Data;
    std::map<std::string, T*> array_Data;

private:
    void dataType();
    void count_rows_and_columns(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator);
    void initialise_memory();
    void fill_2D_Array();
    void fill_2D_Vector(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator);
    void fill_2D_Vector_map();
    
    T& operator[](const T* csv_data_);
    
public:
    CSV_Reader();
    ~CSV_Reader();

public:
    void read_Data(const std::string& file_name, const bool& headers_, const bool& units_, const char& separator);
    
    const int& get_row_count_with_headers() const;
    const int& get_row_count_without_headers() const;
    const int& get_column_count() const;
    
    const std::string& get_data_type() const;
    const std::vector<T>& get_VectorData_in_row(const int& row_num);
    const std::vector<T>& get_VectorData_under_header(const std::string& header_name);
    const std::vector<std::vector<T>>& get_VectorData_without_headers() const;
    const std::vector<std::vector<T>>& get_transpose_VectorData_without_headers();
    const std::vector<std::string>& get_headers() const;
    const std::vector<std::string>& get_units() const;
    const std::map<std::string, std::vector<T>>& get_Vector_Data() const;
    
    const T* get_ArrayData_in_row(const int& row_num);
    //const T& get_ArrayData_under_header(const std::string& header_name);
    //const std::map<std::string, T*>& get_Array_Data();
    const T* get_ArrayData_without_headers() const;

};

template <typename T>
class CSV_Writer{
    
private:
    std::vector<std::string>headers;
};

#endif /* CSV_tools_hpp */
