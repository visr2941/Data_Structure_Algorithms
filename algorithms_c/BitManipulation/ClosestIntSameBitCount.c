//
//  ClosestIntSameBitCount.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/12/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "ClosestIntSameBitCount.h"

/*
 Problem:
    Find the closest number y with same weight as x in terms of bit count such that
    |y - x| is minimum.
 
 Solution:
    Swap the first two LSB non-matching consecutive bits.
 
 Explaination:
    To keep the number of set bits same and have a new number closest to the original,
    we will have to swap one 0 to one 1. We must start with LSB as flipping LSB should
    give the minimum change in the number. Let's say we swap two non-matching bits of x
    at position k1 and k2 producing x1. The |x-x1| will be |2^k1 - 2^k2| and to minimize
    it k1 should be as close as k2 and k1 should be minimum.
*/

uint32 ClosestIntSameBitCount(uint32 input)
{
    uint32 t = 0, res = 0;
    
    for(int j = 0; j < 31; j++)
    {
        if((input & (1U << j)) != (input & (1U << (j+1))))
        {
            t = (1U << j) | (1U << (j+1));
            res = input^t;
            
            return res;
        }
    }
    
    return input;
}
