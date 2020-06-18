#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
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



bool isValidSudoku(vector<vector<char>>& board) {
    bool buf[9];
    
    for (int i = 0; i < 9; ++i) {
        memset(buf, false, sizeof(buf));
        for (int j = 0; j < 9; ++j) {
            char c = board[i][j];
            if (c == '.') continue;
            bool * tmp = & buf[c-'0'-1];
            if (*tmp == true) return false;
            *tmp = true;
        }
    }

    for (int i = 0; i < 9; ++i) {
        memset(buf, false, sizeof(buf));
        for (int j = 0; j < 9; ++j) {
            char c = board[j][i];
            if (c == '.') continue;
            bool * tmp = & buf[c-'0'-1];
            if (*tmp == true) return false;
            *tmp = true;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            memset(buf, false, sizeof(buf));
            for (int l = 0; l < 3; ++l) {
                for (int m = 0; m < 3; ++m) {
                    char c = board[3*i+l][3*j+m];
                    // cout << c << endl;
                    if (c == '.') continue;
                    bool * tmp = & buf[c-'0'-1];
                    if (*tmp == true) return false;
                    *tmp = true;
                }
            }
        }
    }

    return true;
}

void print_res(vector<vector<char>>& board) {
    bool res = isValidSudoku(board);
    print_vec_vec("board", board);
    cout << "isValidSudoku: " << (res? "True": "False") << endl;
}

int main() {
    vector<vector<char>> b1 = 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    vector<vector<char>> b2 = 
    {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    print_res(b1);
    print_res(b2);
}
