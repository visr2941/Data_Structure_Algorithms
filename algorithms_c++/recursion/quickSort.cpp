#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

/*
Quick Sort
We have to select a pivot randomly and then use that pivot to partition the array into two parts;
one part having all the elements smaller than the pivot and the other parts to have all elements 
either smaller or equal (we can make all elements equal to pivot on left side as well). We can  
run quickSort on each part now and keep doing this until we have one element in the divided parts.
At the end, we will have sorted array.
There are different parition algorithm we have for ex: Hoare's partition or Lomuto's partition. We will 
implement both - for Hoare's we will modify it slightly 

Algorithm:
quickSort(arr, l = 0, h = n-1):
    if l < h:
        piv = partition(arr, l, h)

        quickSort(arr, l, piv-1)
        quickSort(arr, piv+1, h)

Partition Algorithm:
Lomuto's Partition:

partition_lomuto(arr, l, h):
    piv_val = arr[h] // one take any element and swap it with first or last element
    i = l-1
    j = l
    for j from l to h-1:
        if arr[j] < piv_val:
            swap(arr[++i], arr[j])

    // at this point, i must be pointing to the rightmost element smaller than pivot
    swap(arr[i+1], arr[h])

    return i+1

Modified Hoare's Algorithm:

    partition(arr, l, h):
        piv_val = arr[h]
        i = l-1
        j = h

        while TRUE:
            while arr[++i] < piv_val:
                continue
            
            while arr[--j] > piv_val:
                if j == l:
                    break

            if i >= j:
                break
            
            swap(arr[i], arr[j])

        swap(arr[h], arr[i])

        return i

Both the above algorithms work good even in the case of duplicate elements, or duplicates pivots but can be improved to
be more efficient using 3-way partition algorithm.
The idea of 3-way partition is to push the duplicate pivots found on left partition to the left most and for the right
partition to the right most. At the end, swap them in the middle.

partition_three_way(arr, l, h):
        piv_val = arr[h]
        i = l-1
        j = h
        k = l-1
        m = h

        while TRUE:
            while arr[++i] < piv_val:
                continue
            
            while arr[--j] > piv_val:
                if j == l:
                    break

            if i >= j:
                break
            
            swap(arr[i], arr[j])

            if arr[i] == piv_val:
                swap(arr[++k], arr[i])

            if arr[j] == piv_val:
                swap(arr[--m], arr[j])

        swap(arr[h], arr[i])

        p = i

        for n = l to k
            swap(arr[--i], arr[n])
        

        i = p

        for n = m to h
            swap(arr[++i], arr[n])

        return (l, p-k-2), (m, h)
*/

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int l, int h)
{
    int piv_val = arr[h];
    int i = l-1;
    int j = h;

    while(true) {
        while(arr[++i] < piv_val);
        while(arr[--j] > piv_val) {
            if (j == l) break;
        }

        if (i >= j) break;

        swap(arr[i], arr[j]);
    }

    swap(arr[i], arr[h]);

    return i;
}

void partition_three_way(int arr[], int l, int h, int* l_last, int* r_first)
{
    int piv_val = arr[h];
    int i = l-1;
    int j = h;

    int k = l-1, n = h;
    int p;

    while(true) {
        while(arr[++i] < piv_val);
        while(arr[--j] > piv_val) {
            if (j == l) break;
        }
        
        if (i >= j) break;

        swap(arr[i], arr[j]);

        if (arr[i] == piv_val) {
            swap(arr[++k], arr[i]);
        }

        if (arr[j] == piv_val) {
            swap(arr[--n], arr[j]);
        }
    }

    swap(arr[i], arr[h]);
    
    p = i;

    int left_cnt = k-l+1;
    int right_cnt = h-n; // h-1-n+1 since last element is pivot

    for (int m = 0; m < left_cnt; ++m) {
        swap(arr[--i], arr[m+l]);
    }
    
    i = p;

    for (int m = 0; m < right_cnt; ++m) {
        swap(arr[++i], arr[m+n]);
    }

    *l_last = p-1-left_cnt;
    *r_first = p+1+right_cnt;
}

void partition_three_way_optimized(int arr[], int l, int h, int* l_last, int* r_first)
{
    int piv_val = arr[h];
    int lt = l, gt = h, i = l;

    while(i <= gt) {
        if (arr[i] < piv_val) {
            if (i != lt) swap(arr[i], arr[lt]);
            i++;
            lt++;
        } else if (arr[i] > piv_val) {
            swap(arr[i], arr[gt--]);
        } else {
            i++;
        }
    }

    *l_last = lt-1; 
    *r_first = i;
}

void quickSort(int arr[], int l, int h)
{
    int l_last, r_first;

    if (l < h) {
        //int piv = partition(arr, l, h);
        //quickSort(arr, l, piv-1);
        //quickSort(arr, piv+1, h);

        partition_three_way_optimized(arr, l, h, &l_last, &r_first);
        quickSort(arr, l, l_last);
        quickSort(arr, r_first, h);
    }
}

int main (void)
{
    int arr[] = {6, 3, 2, 6, 7, 8, 4, 5, 4, 6, 8, 2, 9, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);

    printArray(arr, n);

    return 0;
}

/*
    auto rd = std::random_device {}; 
    
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(nums), std::end(nums), rng);
*/