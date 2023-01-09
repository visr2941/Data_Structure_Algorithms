#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

/*
    Merge Sort
    vactor or array of size n:
    Algo:
        if (n <= 1)
            return

        MergeSort(arr, n/2)
        MergeSort(arr+n/2, n-n/2)

        Merge(arr, arr+n/2) // Merge will require O(n) space and O(n) time. 
S
    Complexity:
        T(n) = 2T(n/2) + O(n)    =>    O(nlogn)

*/

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v)
{
    for (auto e : v)
        out << e << " ";

    return out;
}

void Merge(vector<int>& v, int s1, int e1, int s2, int e2)
{
    vector<int> merged;
    int st = s1;

    while (s1 <= e1 && s2 <= e2) {       
        if (v[s1] < v[s2]) {
            merged.push_back(v[s1]);
            ++s1;
        } else {
            merged.push_back(v[s2]);
            ++s2;
        }
    }

    while (s2 <= e2) merged.push_back(v[s2++]);
    while (s1 <= e1) merged.push_back(v[s1++]); 

    std::copy(merged.begin(), merged.end(), v.begin() + st);
}

void MergeSort(vector<int>& v, int st, int end)
{
    if (st >= end) return;

    int mid = st + (end-st+1)/2;

    MergeSort(v, st, mid-1);
    MergeSort(v, mid, end);

    Merge(v, st, mid-1, mid, end);
}

int main(void)
{
    vector<int> v {3, 1, 5, 7, 12, 2, 6, 4};

    MergeSort(v, 0, v.size()-1);

    cout << v << endl;

    return 0;
}