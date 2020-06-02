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

// https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66140/My-concise-O(m%2Bn
// more solution: https://leetcode.wang/leetcode-240-Search-a-2D-MatrixII.html?h=matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();
    if (n == 0) return false;


    for (int i = 0, j = n-1; i < m && j >= 0;) {
        int cur = matrix[i][j];
        if (cur < target) {
            i++;
        } else if (cur > target) {
            j--;
        } else {
            return true;
        }
    }

    return false;
}

void print_res(vector<vector<int>>& matrix, int target) {
    print_vec_vec("m: ",matrix);
    string result = searchMatrix(matrix, target)? "True" : "False";
    cout << "searchMatrix: " << result << endl;
}

int main() {
    vector<vector<int>> m1 = 
    {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    print_res(m1, 5);
    print_res(m1, 20);
}
