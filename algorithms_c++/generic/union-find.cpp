/*
    Union-Find Algorithm

    Problem:
    There are N objects and we can connect them in pair and a single object can be indirectly connected
    to multiple objects. We need to develop an algorithm to connect (union) objects and find if they are
    connected.

    For computer programming purpose, it's good to map the object to an integer number and then work with
    that number.

    Setup:
    we define an array of size N and each object is represented by the index of that array,

    Algorithm 1:
    Each array element represent the object-number it's connected to. To start, each object is connected to 
    itself. SO, array will be initialized with it's index value.
    
    Union(y,x):
    Let's update arr[y] to value arr[x]. This will connect object x and y. In case where, y was already connected
    to other objects, say a & b, and arr[y] has value of a (after operation union(b,a) -> union(y, a)), this will
    disconnect the y with a & b. So keep the connected component together we have to update each element with value
    arr[y] to arr[x].
    Code:
        val <- arr[y]
        
        for i: 0 to N-1:
            if val == arr[i]
                arr[i] <- arr[x]

    Complexity: O(n)

    Find(y,x):
    Code:
        return arr[y] == arr[x]

    Complexity: O(1)

    Algorithm2:
    Let's put each of the connected component in the form of a tree and update array element to the value of its parent 
    object.

    Root(l):
    code:
        while l != arr[l]:
            l = arr[l]
        
        return l

    Union(y,x):
    code: 
        val1 = root(y)
        val2 = root(x)

        arr[val1] = val2

    Complexity: O(n) in worst case because tree can get taller if union happens in certain steps.

    Find(y,x):
    code:
        return root(y) == root(x)

    Complexity: O(n) in worst case

    This algorithm can be better than algorithm1 but in worst case it still is O(n) and now Find also becomes O(n)

    Algorithm3:
    To avoid tree get taller, let's measure the size of tree before connecting. The node having bigger tree will connect
    the node with smaller tree (number of elements in tree) and this way the tree will have balance before it gorws too tall.
    In this case, the farthers node at the leaf can't be more than logN times far because tree depth only grow by 1 at max and 
    certainly grow by 1 in case where tree have equal size. 
    To track the size of the tree, we need to create one more array with N elements, initialized to 1. sz[N]

    Union(y,x):
    l1 = Root(y)
    l2 = Root(x)

    if sz[y] >= sz[x]:
        arr[l2] = arr[l1]
        sz[l1] += sz[l2]
    else:
        arr[l1] = arr[l2]
        sz[l2] += sz[l1]

    Complexity: O(log(n))

    Find(y,x):
        return Root(x) == Root(y)

    Complexity: O(log(n))

    This one is much improved from the last two. 

    We can further improve this algorithm by using path-compression i.e. updating parent of each node to grandparent
    in each call to Root() -> this will help in keeping the tree flat (by cutting the length of node to half):

    Root(l):
    code:
        while l != arr[l]:
            arr[l] = arr[arr[l]]
            l = arr[l]
        return l

*/

#include <iostream>
#include <cstring>

using namespace std;

#define N (10u)

int32_t root(int32_t* arr, uint32_t n, int32_t l)
{
    while (l != arr[l]) {
        arr[l] = arr[arr[l]]; // path compression -> cutting the distance to half
        l = arr[l];
        if (l >= n) {
            return -1;
        }
    }

    return l;
}

void quick_union(int32_t* arr, int32_t* sz, uint32_t n, int32_t x, int32_t y)
{
    // -ve index will translate to positive number during
    // comparison with unsigned n
    if (x >= n || y >= n || !arr || !sz || !n) {
        return;
    }

    int32_t l1 = root(arr, n, x);
    int32_t l2 = root(arr, n, y);

    if (l1 >=  n || l2 >= n) {
        return;
    }

    if (sz[l1] >= sz[l2]) {
        arr[l2] = l1; // or = arr[l1]
        sz[l1] += sz[l2];
    } else {
        arr[l1] = l2; // or = arr[l2]
        sz[l2] += sz[l1];
    }
}

bool quick_find(int32_t* arr, uint32_t n, int32_t x, int32_t y)
{
    return root(arr, n, x) == root(arr, n, y);
}

int main(void)
{
    int arr[N];
    int sz[N];

    for (int i = 0; i < N; ++i) {
        arr[i] = i;
        sz[i] = 1;
    }

    quick_union(arr, sz, N, 1, 5);
    quick_union(arr, sz, N, 2, 6); 
    quick_union(arr, sz, N, 7, 9);
    quick_union(arr, sz, N, 1, 6);
    quick_union(arr, sz, N, 1, 8);

    cout << "Are 1 and 2 connectd? " << quick_find(arr, N, 1, 2) << endl;
    cout << "Are 5 and 2 connectd? " << quick_find(arr, N, 5, 2) << endl;
    cout << "Are 9 and 2 connectd? " << quick_find(arr, N, 9, 2) << endl;

    return 0;

}