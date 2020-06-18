#include <iostream>
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

void rotate(vector<vector<int>>& matrix) {
    int m = matrix.size();

    for (int start = 0; start < m / 2; ++start) {
        int end = m - 1 - start;

        for (int i = 0; i < end - start; ++i) {
            int* a = & matrix[start][start+i];
            int* b = & matrix[start+i][end];
            int* c = & matrix[end][end-i];
            int* d = & matrix[end-i][start];

            swap(*a,*b);
            swap(*c,*d);
            swap(*a,*c);
        }
    }
}

void print_res(vector<vector<int>>&m) {
    print_vec_vec("before", m);
    rotate(m);
    print_vec_vec("after", m);
}

int main() {
    vector<vector<int>> m1 = 
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<vector<int>> m2 = 
    {
        { 5, 1, 9,11},
        { 2, 4, 8,10},
        {13, 3, 6, 7},
        {15,14,12,16}
    };


    print_res(m1);
    print_res(m2);
}
