//
//  processInput.cpp
//  Break the Vault
//
//  Created by Apaulture on 1/25/20.
//  Copyright © 2020 Apaulture. All rights reserved.
//

#include "processInput.hpp"
#include <iostream>

// Get inputs (3)
int getInput()
{
    int code{};
    std::cin >> code;
    
    return code;
}

// Process inputs
int processSum(int codeA, int codeB, int codeC)
{
    return codeA + codeB + codeC;
}

int processMultiple(int codeA, int codeB, int codeC)
{
    return codeA * codeB * codeC;
}
