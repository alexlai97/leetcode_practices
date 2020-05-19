#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string,vector<string>> mp;

    for (auto s: strs) {
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        mp[tmp].push_back(s);
    }

    for (auto x: mp) {
        res.push_back(x.second);
    }

    return res;
}

void print_res(string name, vector<string> &strs) {
    auto res = groupAnagrams(strs);
    cout << name << " ";
    print_vector("strs", strs);
    print_vec_vec("groupAnagrams: ", res);
}


int main() {
    vector<string> strs1 =  {"eat", "tea", "tan", "ate", "nat", "bat"};
    print_res("strs1", strs1);
}
