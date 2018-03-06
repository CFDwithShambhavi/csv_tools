//
//  main.cpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 2/26/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//
#include "CSV_tools.cpp"

int main() {
        
    std::string path_name = "/Users/snandan/CSV_tools/CSV_tools/";
    std::string file_name = path_name + "Most-Recent-Cohorts-Scorecard-Elements.csv";
    CSV_Reader<float> load_data;
    load_data.read_Data(file_name, true, false, ',');
    const float* p = load_data.get_ArrayData_in_row(0);
    
    std::cout<< load_data.get_row_count_with_headers() <<std::endl;
    
    std::vector<std::string> headers;
    headers.reserve(load_data.get_column_count());
    headers = load_data.get_headers();
    
    std::cout<<headers.size()<<std::endl;
    
    for(int i = 0; i < headers.size(); i++) {
        std::cout<<p[i]<<std::endl;
    }

        return 0;
}
