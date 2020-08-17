//
//  ReverseDigits.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/12/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "ReverseDigits.h"

uint32 ReverseDigits(uint32 input)
{
    if((input == 0) || (input/10 == 0)) return input;
    
    uint32 res = 0;
    
    while(input)
    {
        res = 10*res + (input%10);
        
        input = input / 10;
    }
    
    return res;
}
