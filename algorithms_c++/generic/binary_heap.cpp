#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

#define NUM_OF_ELEMS (250u)
#define K (40u)

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

    // to set separate random seed, current time is used to generate 
    // different seed everytime. If we don't do this, rand() will use
    // srand(1) and produce same random sequence everytime we call 
    //srand(time(0)); 
    for (int i = 0; i < vec.size(); ++i) {
        r = rand() % (i+1);
        swap(vec[i], vec[r]);
    }
}

class MaxHeap
{
private:
    int N = 0;
    int curr_size = 0;
    int* arr = NULL;

    bool is_less(int c1, int c2)
    {
        if (c2 > curr_size) return false;
        return (arr[c1] < arr[c2]);
    }

    void heapify_down(int k)
    {
        int c = 2*k;

        while(c <= curr_size) {
            if(is_less(c, c+1)) ++c;
            if (!is_less(k, c)) break;
            swap(arr[c], arr[k]);
            k = c;
            c = 2*k;
        };
    }

    void heapify_up(int k)
    {
        int p = k/2;

        while (p > 0 && is_less(p, k)) {
            swap(arr[p], arr[k]);
            k = p;
            p = k/2;
        }
    }

    bool find(int elem, int st, int* ind)
    {
        if (arr[st] == elem) {
            *ind = st;
            return true;
        }

        int c=2*st;
        if (arr[st] < elem || c > curr_size) return false;

        if (arr[c] < elem) {
            return find(elem, c+1, ind);
        }
        
        return (find(elem, c, ind) || find(elem, c+1, ind));
    }

public:
    MaxHeap(int capacity): N(capacity+1)
    {
        arr = new int[N];
    }

    bool insert(int elem)
    {
        if (curr_size >= (N-1)) {
            return false;
        }

        arr[++curr_size] = elem;
        heapify_up(curr_size);

        return true;
    }

    bool remove(int elem)
    {
        if (curr_size == 0) return false;
        
        int ind;
        if (!find(elem, 1, &ind))  {
            cout << "elem : " << elem << " not found!!!" << endl;
            return false;
        }

        swap(arr[ind], arr[curr_size--]);
        heapify_down(ind);

        return true;
    }

    int top(void)
    {
        if (curr_size == 0) {
            cerr << "No elements in heap" << endl;
            abort();
        }
        return arr[1];
    }

    int pop(void)
    {
        if (curr_size == 0) {
            cerr << "No elements in heap" << endl;
            abort();
        }
        int result =  arr[1];
        this->remove(arr[1]);
        return result;
    }

    int size(void)
    {
        return curr_size;
    }

    void print_heap(void)
    {
        for (int i = 1; i <= curr_size; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void print_array(void)
    {
        for (int i = 1; i < N; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    vector<int> get_all_elements()
    {
        vector<int> result;

        while(this->size() != 0) {
            result.push_back(this->pop());
        }

        return result;
    }

    void sort()
    {
        for (int i = curr_size/2; i > 0; --i) {
            heapify_down(i);
        }

        for (int i = curr_size; i > 1; --i) {
            swap(arr[1], arr[i]);
            curr_size--;
            heapify_down(1);
        }
    }
};

int main (void)
{
    MaxHeap maxHeap(K);
    vector<int> vec(NUM_OF_ELEMS);
    vector<int> result(K);

    for (int i = 0; i < NUM_OF_ELEMS; ++i) vec[i] = i;

    shuffle(vec);
    cout << vec << endl;

    // for (int i = 0; i < NUM_OF_ELEMS; ++i) {
    //     if (maxHeap.size() < K) {
    //         maxHeap.insert(vec[i]);
    //     } else if (maxHeap.top() > vec[i]) {
    //         maxHeap.pop();
    //         maxHeap.insert(vec[i]);
    //     }
    // }

    // for (int i = 0; i < K; ++i) {
    //     result[K-i-1] = maxHeap.pop();
    // }

    // cout << "smallest K=" << K << " elements:" << endl;
    // cout << result << endl;

    for (int i = 0; i < K; ++i) {
        maxHeap.insert(vec[i]);
    }

    maxHeap.print_heap();

    // maxHeap.remove(152);
    // maxHeap.remove(30);
    // maxHeap.remove(183);
    // maxHeap.remove(136);

    maxHeap.sort();

    maxHeap.print_array();

    return 0;
}