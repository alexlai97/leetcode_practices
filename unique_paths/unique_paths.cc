#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    int table[m][n];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i==0 || j==0) {
                table[i][j] = 1;
            } else {
                table[i][j] = table[i-1][j] + table[i][j-1];
            }
        }
    }
        
    return table[m-1][n-1];
}

int main() {
    int m = 3;
    int n = 7;
    int output = uniquePaths(m,n);
    cout << "uniquePaths("<<m<<","<<n<<") = " <<output << endl;
}
