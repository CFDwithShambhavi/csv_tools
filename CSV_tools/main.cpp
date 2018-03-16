//
//  main.cpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 2/26/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//
#include "CSV_Reader.cpp"

int main() {
        
    std::string path_name = "/Users/snandan/CSV_tools/CSV_tools/";
    std::string file_name = path_name + "Most-Recent-Cohorts-Scorecard-Elements.csv";
    CSV_Reader<std::string> load_data(file_name, true, false, ',');
    load_data.readData();
    std::vector<std::string> h = load_data.getVectorHeaders();
    int r = load_data.getRowCountWithoutHeaders();
    const std::string* d = load_data.getArrayDataUnderHeader("CITY");
    
    
    std::cout<<h.size()<<std::endl;
    
    for(int i = 0; i < r; i++) {
        std::cout<<d[i]<<std::endl;
    }

        return 0;
}
