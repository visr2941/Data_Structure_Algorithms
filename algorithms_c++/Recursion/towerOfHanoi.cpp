#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

/*
    Tower of Hanoi:
    There are three rods, A, B and X. Rod A has n number of disks in ascending order of size, smallest being on top. 
    Transfer all the disks from rod A to rod B using rod X in such a way that never a bigger disk is on top of smaller disk.

    Function: solveTowerOfHanoi
    Arg: n, src, dest, aux
    Return: void

    Algo:
        if n == 0: 
            return

        solveTowerOfHanoi(n-1, src, aux, dest);
        move disk n from src to dest
        solveTowerOfHanoi(n-1, aux, dest, src)

    Complexity:
        T(n) = T(n-1) + 1    =>    O(2^n)

*/

typedef struct _rod_t {
    stack<int>& st;
    char ch;

    _rod_t(stack<int>& st, char ch) : st(st), ch(ch) {}
} rod_t;

void towerOfHanoi_recursive(int n, rod_t& src, rod_t& dest, rod_t& aux)
{
    if (!n) return;

    towerOfHanoi_recursive(n-1, src, aux, dest);

    cout << "moving disk " << src.st.top() << " from " << src.ch << " to " << dest.ch << endl; 
    
    dest.st.push(src.st.top()); src.st.pop();

    towerOfHanoi_recursive(n-1, aux, dest, src);
}

void towerOfHanoi_recursive_just_number(int n, char src, char dest, char aux)
{
    if (!n) return;

    towerOfHanoi_recursive_just_number(n-1, src, aux, dest);

    cout << "moving disk " << n << " from " << src << " to " << dest << endl; 
    
    towerOfHanoi_recursive_just_number(n-1, aux, dest, src);
}

void towerOfHanoi_iterative(int n, rod_t& src, rod_t& dest, rod_t& aux)
{
    int total_iteration = (pow(2, n) - 1)/3;

    for (int i = 0; i < total_iteration; ++i) {
        if (aux.st.empty() || (!src.st.empty() && src.st.top() < aux.st.top())) {
            aux.st.push(src.st.top()); src.st.pop();
        } else if (src.st.empty() || (!aux.st.empty() && src.st.top() > aux.st.top())) {
            src.st.push(aux.st.top()); aux.st.pop();
        }

        if (dest.st.empty() || (!src.st.empty() && src.st.top() < dest.st.top())) {
            dest.st.push(src.st.top()); src.st.pop();
        } else if (src.st.empty() || (!dest.st.empty() && src.st.top() > dest.st.top())) {
            src.st.push(dest.st.top()); dest.st.pop();
        }

        if (dest.st.empty() || (!aux.st.empty() && aux.st.top() < dest.st.top())) {
            dest.st.push(aux.st.top()); aux.st.pop();
        } else if (aux.st.empty() || (!dest.st.empty() && aux.st.top() > dest.st.top())) {
            aux.st.push(dest.st.top()); dest.st.pop();
        }
    }

    // when n is odd, aux will have all the disks moved from src 
    if (!src.st.empty()) {
        aux.st.push(src.st.top()); src.st.pop();
    }
}

void towerOfHanoi(std::stack<int>& A, std::stack<int>& B)
{
    stack<int> aux;
    rod_t src_local(A, 'A'), dest_local(B, 'B'), aux_local(aux, 'X');

    towerOfHanoi_recursive(src_local.st.size(), src_local, dest_local, aux_local);

    // if (src_local.st.size() % 2) {
    //     towerOfHanoi_iterative(src_local.st.size(), src_local, aux_local, dest_local);
    // } else {
    //     towerOfHanoi_iterative(src_local.st.size(), src_local, dest_local, aux_local);
    // }
}

int main(void)
{
    stack<int> A, B;
    int num_elem = 5;
    for (int i = num_elem; i >= 1; --i) {
        A.push(i);
    }

    towerOfHanoi(A, B);

    for (int i = 0; i < num_elem; ++i) {
        cout << B.top() << endl; B.pop();
    }

    towerOfHanoi_recursive_just_number(5, 'A', 'B', 'X');

    return 0;
}