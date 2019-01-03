#include <stdio.h>
#include <stdlib.h>

//#include <malloc.h>

int fun_func(int x) 
{
    int f = printf("fun %d\n", x);
    
    return 0;
}

#define fun_func(x) ({ \
                        fun_func(x+5); \
                    })

int main()
{
    char * s = (char*) malloc(10);
    
    s = "vishal srivastav";
    
    printf("Hello, World %d!\n", fun_func(5));

    return 0;
}
