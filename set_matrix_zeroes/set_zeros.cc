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

void setZeroes(vector<vector<int>>& matrix) {
    bool isCol = false;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0 ; i < m; ++i)  {
        if (matrix[i][0] == 0) 
            isCol = true;

        for (int j = 1 ; j < n; ++j)  {
            if (matrix[i][j] == 0)  {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    print_vec_vec("here1", matrix);

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    print_vec_vec("here2", matrix);
    if (matrix[0][0] == 0)  {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }
    print_vec_vec("here3", matrix);

    if (isCol)  {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
}

void print_res(string name, vector<vector<int>>& matrix) {
    print_vec_vec(name+" before",matrix);
    setZeroes(matrix);
    print_vec_vec(name+" after",matrix);
}

int main() {
    vector<vector<int>> m1 = {
        { 1,1,1 },
        { 1,0,1 },
        { 1,1,1 }
    };
    vector<vector<int>> m2 = {
        { 0,1,2,0 },
        { 3,4,5,2 },
        { 1,3,1,5 }
    };
    vector<vector<int>> m3 = {
        { 1,1,1 },
        { 0,1,2 }
    };

    print_res("m1", m1);
    // print_res("m2", m2);
    // print_res("m3", m3);
}
