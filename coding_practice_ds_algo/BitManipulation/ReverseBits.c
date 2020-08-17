//
//  ReverseBits.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/12/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "ReverseBits.h"

uint8 ReverseBits(uint8 byte)
{
    uint8 t1 = 1, t2 = ~0, res = 0;
    
    t2 >>= 1;
    t2 = ~t2;
    
    while(t2 > t1)
    {
        if(t2 & byte) res |= t1;
        
        if(t1 & byte) res |= t2;
        
        t1 <<= 1;
        t2 >>= 1;
    }
    
    return res;
}
