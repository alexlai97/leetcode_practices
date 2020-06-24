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


vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows <= 0) return res;
    res.push_back(vector<int>{1});
    for (int i = 0; i < numRows-1; ++i) {
        vector<int> &last = res.back();
        vector<int> row;
        row.push_back(1);
        for (int j = 0; j < last.size()-1; ++j) {
            row.push_back(last[j]+last[j+1]);
        }
        row.push_back(1);
        res.push_back(row);
    }
    return res;
}

void print_res(int numRows) {
    auto res = generate(numRows);
    cout << "pascal's triangle with n: " << numRows << endl;
    print_vec_vec("", res);
}

int main() {
    print_res(5);
    print_res(0);
}
