//
//  SwapBits.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/12/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "SwapBits.h"

uint64 SwapBits(uint64 input, uint8 i, uint8 j)
{
    uint64 t = 1;

    if(((input >> i) & 1) != ((input >> j) & 1))
    {
        t = ((1 << i) | (1 << j));
        
        return (input ^ t);
    }
    
    return input;
}
