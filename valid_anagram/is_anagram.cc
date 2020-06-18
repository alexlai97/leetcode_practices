#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {

    unordered_map<char,int> mp;
    for (auto c : s) {
        mp[c] ++;
    }
    for (auto c : t) {
        mp[c] --;
        if (mp[c] < 0) return false;
    }

    for (auto p: mp) {
        if (p.second != 0) return false;
    }
    return true;

}

void print_res(string s, string t) {
    bool flag = isAnagram(s,t);
    cout << s << " v.s. " << t << endl;
    cout << (flag ? "True" : "False") << endl;
}


int main() {

    print_res("anagram", "nagaram");
    print_res("rat", "car");

}
