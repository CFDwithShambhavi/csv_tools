//
//  CSV_tools.cpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 2/26/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#include "CSV_tools.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

template <typename T>
class Load_Data: public CSV_tools<T> {
    
public:
    T read_data(const std::string& file_name) override {
            
        std::ifstream  data(file_name);
        
        int row_count =0 ;
        
        
        std::string line;
        while(std::getline(data,line))
        {
            row_count +=1;
            
            std::stringstream  lineStream(line);
            std::string        cell;
            int column_count = 0 ;
            
            while(std::getline(lineStream,cell,';'))
            {
                column_count+=1;
                // You have a cell!!!!
                if ( column_count == 7){
                    std::cout << cell << std::endl;
                }
            }
        }
    }
    
};
