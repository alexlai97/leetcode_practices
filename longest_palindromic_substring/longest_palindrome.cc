#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Dynamic programming
// wierd that it doesn't pass a test, but it works locally
string longestPalindrome(string s) {
    int len = s.size();
    if (len == 0) return "";
    
    int **table = new int*[len];
    for (int i = 0; i < len; ++i) {
        table[i] = new int[len];
    }

    int j;

    int max_i,max_j;
    int max_len = 1;
    for (int k = 0; k < len; ++k) {
        for (int i = 0; i < len-k; ++i) {
            j = i+k;
            // cout << "i: " << i << ", j: " << j << endl;
            if (k == 0) {
                table[i][j]=true;
                // cout << "case1" << endl;
            } else if (k == 1) {
                if (s[i] == s[i+1]) { 
                    table[i][j] = true;
                    // cout << "case2" << endl;
                }
            } else {
                table[i][j] = table[i+1][j-1] && s[i] == s[j];
                // if (table[i][j] == true) 
                    // cout << "case3" << endl;
            }
            if (table[i][j] == true) {
                int cur_len = j-i+1;
                if (cur_len > max_len) {
                    max_len = cur_len;
                    max_i = i;
                    max_j = j;
                    // cout << "max_i: " << max_i << ", max_j: " << max_j << ", max_len: " << max_len << endl;
                }
            }
        }
    }

    for (int i= 0 ; i < len; ++i) {
        delete[] table[i];
    }
    delete [] table;

    return s.substr(max_i,max_len);
}

int expandAroundCenter(string &s, int left, int right);

// Approach 4: Expand Around Center
string longestPalindrome2(string s) {
    int len = s.size();
    if (s.empty()) return "";
    int start = 0, end = 0;
    for (int i = 0; i < len; ++i) {
        int len1 = expandAroundCenter(s,i,i);
        int len2 = expandAroundCenter(s,i,i+1);
        int len = max(len1,len2);
        if (len > end - start) { 
            start = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(start,end-start+1);
}

int expandAroundCenter(string &s, int left, int right) {
    int L = left, R = right;
    while (L >= 0 && R < s.size() && s[L] == s[R]) {
        L--;
        R++;
    }
    return R-L-1;
}

void print_res(string s) {
    cout << "s: " << s << endl;
    cout << "longestPalindrome: " << longestPalindrome2(s) << endl;
}

int main() {
    print_res("cbbd");
    print_res("babad");
    print_res("aaabaaaa");
}
