
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

/* function to change the integer value to nBits bit string */
/* It could have been also implemented using stack STL */
string Int2bin(int intValue, int nBits = 8)
{
    if (nBits<0)
    {
        cerr << "error: nBits can't be negative" << endl;
        exit(1);
    }
    
    if(intValue >= pow(2,nBits) || intValue < 0)
    {
        cerr << "error: number out of range (default is 8 bits reprsentation) or negative" << endl;
        exit(1);
    }
    
    string bin;
    int divi = intValue, rem, i=0;
    char arr[nBits] = {0};
    
    while(--nBits)
    {
        rem = divi%2;
        arr[nBits] = (rem+48);
        divi = divi/2;
    }
    arr[0] = (divi+48);
    
    while(i<sizeof(arr))
        bin += arr[i++];
    
    
    return bin;
}
