//
//  MultiplyUsingBitManipulation.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/12/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "MultiplyUsingBitManipulation.h"

static uint64 Add(uint64 a, uint64 b)
{
    uint64 carry = 0;
    
    while(b)
    {
        carry = a & b;
        
        a ^= b;
        
        b = carry << 1;
    }
    
    return a;
}

uint64 MultiplyUsingBitManipulation(uint32 x, uint32 y)
{
    uint64 res = 0;
     
    for(int i = 0; i < 32; i++)
    {
        if(y & (1L << i))
        {
            res = Add(res, ((uint64)x << i));
        }
    }
    
    return res;
}
