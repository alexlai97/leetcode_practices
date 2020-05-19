#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    cout << name << ": [";
    for (auto i: v) cout << i << ", ";
    cout << "]" << endl;
}


// Approach 2: Backtracking
// still not quite understand backtracking
void backtrack(vector<string> &ans, string cur, int open, int close, int max) {
    if (cur.size() == max * 2) {
        ans.emplace_back(cur);
        return;
    }

    if (open < max) {
        backtrack(ans, cur + '(', open+1, close, max);
    }
    if (close < open) {
        backtrack(ans, cur + ')', open, close+1, max);
    }
}
vector<string> generateParenthesis2(int n) {
    vector<string> ans;
    backtrack(ans, "", 0,0,n);
    return ans;
}

// Approach 3: Closure Number from solution
// still not quite understand what is the closure number
vector<string> generateParenthesis3(int n) {
    vector<string> ans;
    if (n == 0) {
        ans.emplace_back("");
    } else {
        for (int c = 0; c < n; ++c) {
            for (auto left: generateParenthesis3(c)) {
                for (auto right: generateParenthesis3(n-c-1)) {
                    string tmp;
                    tmp.append("(");
                    tmp.append(left);
                    tmp.append(")");
                    tmp.append(right);
                    ans.emplace_back(tmp);
                }
            }
        }
    }
    return ans;
}

int main() {
    int n = 3;
    vector<string> res = generateParenthesis2(n);
    print_vector("res", res);
}
