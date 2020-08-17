//
//  CalculatePower.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/12/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "CalculatePower.h"

double CalculatePower(double x, int32 y)
{
    double res = 1.0;
    
    if(y < 0)
    {
        x = 1.0/x;
        y = -y;
    }
    
    while(y)
    {
        if(y&1) res = res * x;
        
        x *= x;
        y >>= 1;
    }
    
    return res;
}
