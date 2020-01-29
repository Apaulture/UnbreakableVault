//
//  numberGenerator.cpp
//  Break the Vault
//
//  Created by Apaulture on 1/25/20.
//  Copyright © 2020 Apaulture. All rights reserved.
//

#include "numberGenerator.hpp"

#include <ctime>
#include <iostream>

// Generate one random code
int generateCode()
{
    srand(time(NULL)); // allows for rand() to be called
    
    return rand() % 5;
}
