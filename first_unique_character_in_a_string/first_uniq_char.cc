#include <iostream>
#include <string>
using namespace std;
int firstUniqChar(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int occur[26] = {0};
    int index[26] = {0};

    for (int i = 0; i < s.size() ; ++i) {
        int pos = s[i] - 'a';
        if (occur[pos] == 0) {
            index[pos] = i;
        } 
        occur[pos]++;
    }


    int m = s.size();
    for (int i = 0; i < 26; ++i) {
        if (occur[i] == 1) {
            m = min(m,index[i]);
        }
    }
    if (m == s.size()) m = -1;

    return m;
}

void print_res(string s) {
    cout << "firstUniqChar" << "(" << s << "): " << firstUniqChar(s) << endl;
}

int main() {

    print_res("leetcode");
    print_res("loveleetcode");
    print_res("ll");
}
