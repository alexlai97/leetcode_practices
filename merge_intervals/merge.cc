#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

template <typename T>
void print_vec_vec(string name, vector<vector<T>>&vec_vec) {
    cout << name << ": {" << endl;
    for (auto i : vec_vec) {
        print_vector("",i);
    }
    cout << "}" << endl;
}

// Approach 1: Connected Components
// TODO:
vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        
    return vector<vector<int>> {};
}

void merge_to_second(vector<int> &i1, vector<int> &i2) {
    i2[0] = min(i1[0], i2[0]);
    i2[1] = max(i1[1], i2[1]);
}

bool sorted_overlap(vector<int> &i1, vector<int> &i2) {
    return i1[1] >= i2[0];
}

// Approach 2: Sort 
vector<vector<int>> merge2(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;

    int len = intervals.size();

    if (len <= 1) return intervals;

    // sort by first element
    sort(intervals.begin(), intervals.end(), [](vector<int>&a,vector<int>&b){ return a[0] < b[0]; });

    for (int i = 0; i < len; ++i) {
        if (i==len-1 || ! sorted_overlap(intervals[i], intervals[i+1])) {
            ans.push_back(intervals[i]);
        } else {
            merge_to_second(intervals[i], intervals[i+1]);
        }
    }
        
    return ans;
}


void print_res(vector<vector<int>>& intervals) {
    vector<vector<int>> res = merge2(intervals);
    print_vec_vec("intervals", intervals);
    print_vec_vec("merged", res);
}

int main() {
    vector<vector<int>> intervals1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> intervals2 = {{1,4},{4,5}};

    print_res(intervals1);
    print_res(intervals2);
}
