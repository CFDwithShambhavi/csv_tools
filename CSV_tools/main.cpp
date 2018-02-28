//
//  main.cpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 2/26/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//
#include "CSV_tools.cpp"

int main() {
    
    CSV_tools<double> load_data;
    load_data.read_data("/Users/snandan/CSV_tools/CSV_tools/nuclea17_1_results_Cuz08_Cox06.csv", ';');
    std::cout<< load_data.get_column_count() <<std::endl;
    std::cout<< load_data.get_row_count() <<std::endl;
    std::vector<std::string> headers = load_data.get_headers();
    std::cout<<headers.size()<<std::endl;
    
    std::vector<double> head_data = load_data.get_data_under_header(headers[3]);
    
    for(int i = 0; i < head_data.size(); i++) {
        std::cout<<head_data[i]<<std::endl;
    }
    
        return 0;
}
