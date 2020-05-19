#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<vector<char>>&board, string &word, int i, int j, int k) {
    int m = board.size();
    int n = board[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n) {
        return false;
    }

    // cout << "i: " << i << ", j: " << j << ", k: " << k << endl;
    if (board[i][j] == word[k]) {
        char tmp = board[i][j];
        board[i][j] = '#';
        if (word.size() -1 == k) {
            board[i][j] = tmp;
            return true;
        } else if (dfs(board,word,i-1,j,k+1) || 
                dfs(board,word,i+1,j,k+1) || 
                dfs(board,word,i,j-1,k+1) || 
                dfs(board,word,i,j+1,k+1)) {
            board[i][j] = tmp;
            return true;
        }
        board[i][j] = tmp;
    }

    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dfs(board,word,i,j,0)) return true;
        }
    }
        
    return false;
}

void print_res(vector<vector<char>>&board, string word) {
    bool res = exist(board,word);
    cout << "\""<< word << "\" "<< (res ? "exist":"not exist") << endl;
}


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

int main() {
    vector<vector<char>> b1 = 
    {
        { 'A','B','C','E' },
        { 'S','F','C','S' },
        { 'A','D','E','E' }
    };
    print_res(b1,"ABCCED");
    print_vec_vec("b1", b1);
    print_res(b1,"SEE");
    print_vec_vec("b1", b1);
    print_res(b1,"ABCB");
    print_vec_vec("b1", b1);
}
