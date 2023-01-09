/*
    Shuffle Algorithm:
    To shuffle an array
    Solution 1.
    - Iterate over array and assign a random number between 0, 1 to each array element (create a new array with object and this new random number)
    - Sort the new array and fille the value in the original array.

    Solution 2 (Knuth).
    - Iterate over the original array
    - At ith iteration, create a random number between 0 and i  (including i), say r
    - Swap the ith element with rth element

    Note: 
    1. At some places people do the 2nd step in algorithm by choosing a random index between 0 to N-1 every time but that doesn't produce correct
       result.
    2. Another variant of the above solution is to choose the index randomle between i+1 to N-1
*/

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

ostream& operator<<(ostream& out, const vector<int>& vec)
{
    for (auto i : vec) {
        cout << i << " ";
    }

    return out;
}

void shuffle(vector<int>& vec)
{
    int r;

    // to set separate random seed, current time is used to generate different seed everytime. If we don't do this,
    // rand() will use srand(1) and produce same random sequence everytime we call 
    srand(time(0)); 
    for (int i = 0; i < vec.size(); ++i) {
        r = rand() % (i+1);
        swap(vec[i], vec[r]);
    }
}

int main (void) 
{
    vector<int> vec {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

    shuffle(vec);

    cout << vec << endl;

    return 0;
}
