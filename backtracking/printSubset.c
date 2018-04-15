/* To print all the subsets of the given character set using "backtracking" algorithm*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "backtracking.h"

int main()
{
    char MainArr[5] = {'M', 'Y', 'Z', 'W', 'X'};

    PrintSubset(MainArr, 5);

    return 0;
}
