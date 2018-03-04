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
    CSV_tools<std::string> load_data;
    load_data.read_Data(file_name, true, false, ',');
    std::cout<< load_data.get_column_count() <<std::endl;
    std::cout<< load_data.get_row_count_with_headers() <<std::endl;
    std::vector<std::string> headers;
    headers.reserve(load_data.get_column_count());
    headers = load_data.get_headers();
    std::cout<<headers.size()<<std::endl;
    int row_num = 0;
    std::vector<std::string> row_data = load_data.get_data_in_row(row_num);
    
    for(int i = 0; i < row_data.size(); i++) {
        //std::cout<<row_data[i]<<std::endl;
    }
    
        return 0;
}
