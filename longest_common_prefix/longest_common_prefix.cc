#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

string longestCommonPrefix(vector<string>& strs) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (strs.empty()) return "";
    int i = 0;
    while (i < strs[0].size()) {
        auto it = strs.begin();
        char c = (*it)[i];
        ++it;
        for (;it < strs.end(); ++it) {
            if ((*it)[i] != c) return strs[0].substr(0,i);
        }
        i++;
    }
    return strs[0].substr(0,i);
}

void print_res(vector<string>&strs) {
    print_vector("strs",strs);
    cout << "longestCommonPrefix:" << longestCommonPrefix(strs) << endl;
}

int main() {
    vector<string> ss1 = {"flower","flow","flight"};
    vector<string> ss2 = {"dog","racecar","car"};
    vector<string> ss3 = {"c","c"};
    vector<string> ss4 = {"c"};

    print_res(ss1);
    print_res(ss2);
    print_res(ss3);
    print_res(ss4);
}
