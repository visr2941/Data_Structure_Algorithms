#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

/*
    Find out the kth smallest element from an array.

    Algorithm:
    - Similar to what we have for quickSort partition algorithm 
    Or
    - We can use priority queue to find the kth smallest element
*/

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& vec)
{
    for (auto e : vec) {
        cout << e << " ";
    }

    return out;
}

void partition_three_way_optimized(vector<int>& nums, int l, int h, int* l_last, int* r_first)
{
    int piv_val = nums[h];
    int lt = l, gt = h, i = l;

    while(i <= gt) {
        if (nums[i] < piv_val) {
            if (i != lt) swap(nums[i], nums[lt]);
            i++;
            lt++;
        } else if (nums[i] > piv_val) {
            swap(nums[i], nums[gt--]);
        } else {
            i++;
        }
    }

    *l_last = lt-1; 
    *r_first = i;
}

int quickSelect(vector<int>& nums, int l, int h, int k)
{
    int l_last = -1, r_first;

    partition_three_way_optimized(nums, l, h, &l_last, &r_first);

    if (k <= l_last+1) {
        return quickSelect(nums, l, l_last, k);
    } else if (k >= r_first+1) {
        return quickSelect(nums, r_first, h, k);
    }

    return nums[l_last+1];
}

int quickSelect_iterative(vector<int>& nums, int l, int h, int k)
{
    int l_last = -1, r_first;

    while (l <= h) {
        partition_three_way_optimized(nums, l, h, &l_last, &r_first);
        if (k <= l_last+1) {
            h = l_last;
        } else if (k >= r_first+1) {
            l = r_first;
        } else {
            break;
        }
    }

    return nums[l_last+1];
}

int kthSmallestElement(vector<int>& nums, int k)
{
    // return quickSelect(nums, 0, nums.size()-1, k);
    return quickSelect_iterative(nums, 0, nums.size()-1, k);

    // priority_queue<int, vector<int>, greater<int>> p_q; // mas heap
    
    // kth smallest will be (n-k+1)th largest
    // int l = nums.size() - k + 1;

    // for (auto e : nums) {
    //     p_q.push(e);

    //     if (p_q.size() > l) p_q.pop();
    // }

    // return p_q.top();
}

int main (void)
{
    //vector<int> nums = {6, 3, 2, 6, 7, 8, 4, 5, 4, 6, 8, 2, 9, 6};
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;

    cout << "kth (k=" << k << ") largest element is " << kthSmallestElement(nums, k) << endl; 
    
    cout << nums << endl;

    return 0;
}

// 2 2 3 4 4 5 6 6 6 6 7 8 8 9 
