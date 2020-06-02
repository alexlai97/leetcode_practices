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


bool isSafe(vector<vector<char>>& grid, bool **visted_grid, int m, int n, int row, int col) {
    return row >= 0 && row < m && col >=0 && col < n && grid[row][col] == '1' && !visted_grid[row][col];
}

void DFS(vector<vector<char>>& grid, bool **visted_grid, int row, int col) {
    int m = grid.size();
    int n = grid[0].size();

    static int rowNbr[] = { -1, 1,  0, 0};
    static int colNbr[] = {  0, 0, -1, 1};

    visted_grid[row][col]=true;

    // loop through neighbours
    for (int i = 0; i < 4; ++i) {
        int curRow = row+rowNbr[i];
        int curCol = col+colNbr[i];

        if (isSafe(grid, visted_grid,m,n, curRow, curCol)) {
            DFS(grid, visted_grid, curRow, curCol);
        }
    }
}


// https://www.geeksforgeeks.org/find-number-of-islands/
int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    int m = grid.size();
    if (m == 0) return count;
    int n = grid[0].size();
    if (n == 0) return count;

    // initialize visted_grid
    bool ** visted_grid = new bool *[m];
    for (int i = 0; i < m; ++i) {
        visted_grid[i] = new bool[n];
        fill(visted_grid[i], visted_grid[i]+n, false);
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j]=='1' && !visted_grid[i][j]) {
                DFS(grid,visted_grid,i,j);
                count++;
            }
        }
    }

    // clean up visted_grid
    for (int i = 0; i < m; ++i) 
        delete [] visted_grid[i];
    delete [] visted_grid;

    return count;
}

void print_res(vector<vector<char>>& grid) {
    print_vec_vec("grid:", grid);
    cout << "numIslands: " << numIslands(grid) << endl;
}

vector<vector<char>>string_grid_to_char_grid(vector<string> sgrid) {
    vector<vector<char>> cgrid;
    for (auto s: sgrid) {
        vector<char> tmp;
        for (auto c: s) 
            tmp.push_back(c);
        cgrid.push_back(tmp);
    }
    return cgrid;
}

int main() {
    vector<vector<char>> g1 = string_grid_to_char_grid(
            vector<string>(
                { "11110" ,
                  "11010" ,
                  "11000" ,
                  "00000" }
                ));

    vector<vector<char>> g2 = string_grid_to_char_grid(
            vector<string>(
                { "11000" ,
                  "11000" ,
                  "00100" ,
                  "00011" }
                ));

    vector<vector<char>> g3 = string_grid_to_char_grid(
            vector<string>(
                { "11000",
                  "11000",
                  "00100",
                  "00011" }
                ));


    print_res(g1);
    print_res(g2);
    print_res(g3);
}
