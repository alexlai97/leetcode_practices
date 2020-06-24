

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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size();
    if (m == 0) return res;
    int n = matrix[0].size();
    if (n == 0) return res;

    // outer layer
    int r1 = 0, c1 = 0, r2 = m - 1, c2 = n - 1;

    while(r1 <= r2 && c1 <= c2) {
        for (int i = c1; i <= c2; ++i) res.push_back(matrix[r1][i]);
        for (int i = r1+1; i <= r2; ++i) res.push_back(matrix[i][c2]);
        if (r1 < r2 && c1 < c2) {
            for (int i = c2-1; i >= c1+1; --i) res.push_back(matrix[r2][i]);
            for (int i = r2; i >= r1+1; --i) res.push_back(matrix[i][c1]);
        }

        r1++;
        c1++;
        r2--;
        c2--;
    }

    return res;
}

void print_res(vector<vector<int>>& matrix) {
    auto res = spiralOrder(matrix);
    print_vec_vec("m", matrix);
    print_vector("sprialOrder", res);
}

int main() {
    vector<vector<int>> m1 = {
        { 1,2,3 },
        { 4,5,6 },
        { 7,8,9 }
    };
    vector<vector<int>> m2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9,10,11,12}
    };
    vector<vector<int>> m3 = {{3},{2}};
    print_res(m1);
    print_res(m2);
    print_res(m3);
}
