//
//  CSV_tools.hpp
//  CSV_tools
//
//  Created by Shambhavi Nandan on 2/26/18.
//  Copyright © 2018 Shambhavi Nandan. All rights reserved.
//

#ifndef CSV_tools_hpp
#define CSV_tools_hpp

#include <stdio.h>
#include <string>

template<typename T>
class CSV_tools {
    
public:
    
    T read_data(const std::string&) = 0;
    T write_data(const std::string&) = 0;
    
};

#endif /* CSV_tools_hpp */
