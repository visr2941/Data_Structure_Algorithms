#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int checkCcw(vector<int>& a, vector<int>& b, vector<int>& c) 
{
    return (((b[0]-a[0])*(c[1]-a[1])) - ((b[1]-a[1])*(c[0]-a[0])));
}

bool checkColinear(vector<int>& x, vector<int>& y, vector<int>& z) 
{
    return ((y[0]-x[0])*(z[1]-x[1])) == ((y[1]-x[1])*(z[0]-x[0]));
}

vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
    if (trees.size() <= 3) {
        return trees;
    }
    
    vector<vector<int>> outer;
    vector<int> lowest;
    vector<vector<int>> colinear_pts;

    // sort to find the tree with lowest y-coord
    sort(trees.begin(), trees.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    lowest = trees[0];
    outer.push_back(lowest);

    cout << lowest[0] << "," << lowest[1] << endl;

    // sort in order of polar angle relative to lowest y coord pt
    sort(trees.begin()+1, trees.end(), [=](const vector<int>& a, const vector<int>& b) {
        double dist0 = sqrt(pow(a[0]-lowest[0], 2) + pow(a[1]-lowest[1], 2));
        double dist1 = sqrt(pow(b[0]-lowest[0], 2) + pow(b[1]-lowest[1], 2));
        double val0 = double(a[0]-lowest[0])/dist0;
        double val1 = double(b[0]-lowest[0])/dist1;

        if (val0 == val1) return dist0 < dist1;
        else return val0 > val1;
    });

    int sz = trees.size(), i = sz-1;
    while (i >= 2) {
        if (!checkColinear(trees[i], trees[i-1], trees[0])) {
            cout << i << endl;
            break;
        }
        --i;
    }

    if (i != (sz-1) && i != 2) {
        cout << "m here" << i << endl;
        for (int j = i, k = sz-1; j < k; ++j, --k) {
            cout << "here" << endl;
            swap(trees[j], trees[k]);
        } 
    }

    cout << trees.size() << endl;
    //cout << trees[5][0] << "," << trees[5][1] << endl;

    for (vector<int> x : trees) {
        cout << x[0] << "," << x[1] << endl;
        // cout << "(" << x[0] << "," << x[1] << ")" >> endl;
    }

    // check for points (3) which makes counter-clockwise starting from lowest 
    outer.push_back(trees[1]);
    for (int i = 2; i < trees.size(); ++i) {
        int sz = outer.size();
        int ccw = checkCcw(outer[sz-2], outer[sz-1], trees[i]);
        if (ccw == 0) {
            int k = i;
            do {
                if (++k < trees.size()) {
                    --k;
                    ccw = 1;
                    break;
                }
                ccw = checkCcw(outer[sz-2], outer[sz-1], trees[k]);
            } while (0 == ccw);
            if (ccw > 0) {
                while (i++ <= k) {
                    outer.push_back(trees[i]);
                }
            } else if (ccw < 0) {
                if (outer.size() > 2) outer.pop_back();
                outer.push_back(trees[k]);
            }
            i = k;
        } else if (ccw > 0) {
            outer.push_back(trees[i]);
        } else {
            if (outer.size() > 2) outer.pop_back();
            outer.push_back(trees[i]);
        }
        
    }

    return outer;
}
  
int main(void)
{
    vector<vector<int>> fence {{3,0},{4,0},{5,0},{6,1},{7,2},{7,3},{7,4},{6,5},{5,5},{4,5},{3,5},{2,5},{1,4},{1,3},{1,2},{2,1},{4,2},{0,3}};

    vector<vector<int>> result = outerTrees(fence);

    cout << "result" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i][0] << ", " << result[i][1] << endl;
    }

    return 0;
}