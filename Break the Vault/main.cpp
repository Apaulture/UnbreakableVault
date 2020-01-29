//
//  main.cpp
//  Break the Vault
//
//  Created by Apaulture on 1/25/20.
//  Copyright © 2020 Apaulture. All rights reserved.
//

#include "numberGenerator.hpp"
#include "processInput.hpp"

#include <ctime>
#include <iostream>

// Sum three int-type arguments
int sumNumbers(int a, int b, int c)
{
    return a + b + c;
}

// Generate 3 pseudo-random codes and return its sum
int getCodes()
{
    int sumCodes{sumNumbers(generateCode(), generateCode(), generateCode())};
    
    std::cout << "Codes should add up to " << sumCodes << ".\n";
    return sumCodes;
}

// Get 3 user inputs and return its sum
int getInputs()
{
    std::cout << "Input your codes: ";
    return sumNumbers(getInput(), getInput(), getInput());
}

// Checks if user inputs and generated codes match
bool verifySum(int code, int input)
{
    return code == input;
}

int main()
{
    // Level settings
    int level{1};
    int maxLevel{5};
    
    // Loop through levels until maxLevel is reached
    while (level <= maxLevel)
    {
        std::cout << "Level " << level << '\n';
        
        if (verifySum(getCodes(), getInputs()))
        {
            std::cout << "Correct!" << "\n\n";
            ++level; // Go to next level
        }
        else
        {
            std::cout << "Wrong, try again!" << "\n\n";
            // Stay at current level
        }
    }
    
    return 0;
}
