//
//  PrintArray.c
//  practice_programming
//
//  Created by Vishal Srivastav on 1/17/20.
//  Copyright © 2020 interview. All rights reserved.
//

#include "PrintArray.h"

void PrintArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}
