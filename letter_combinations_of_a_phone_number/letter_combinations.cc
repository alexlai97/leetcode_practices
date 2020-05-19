#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char,string> table = {
    { '2', "abc" },
    { '3', "def" },
    { '4', "ghi" },
    { '5', "jkl" },
    { '6', "mno" },
    { '7', "pqrs" },
    { '8', "tuv" },
    { '9', "wxyz" }
};

vector<string> letterCombinations(string digits) {
    vector<string> results;
    if (digits == "") return results;
    
    results.emplace_back("");

    for (auto d : digits) {
        vector<string> new_results;
        for (auto c : table[d]) {
            for (auto s : results) {
                string s_copy = s;
                s_copy.push_back(c);
                new_results.emplace_back(s_copy);
            }
        }
        results = new_results;
    }

    return results;
}

void backtrack(vector<string> &ans, string combinations, string next_digits) {
    if (next_digits.empty()) { 
        ans.emplace_back(combinations);
        return;
    }
    char d = next_digits[0];
    for (auto c : table[d]) {
        string tmp = combinations;
        tmp.push_back(c);
        backtrack(ans, tmp, next_digits.substr(1));
    }
}


vector<string> letterCombinations2(string digits) {
    vector<string> ans;
    if (!digits.empty()) {
        backtrack(ans, "", digits);
    }
    return ans;
}

int main() {
    string nums = "279";
    vector<string> results = letterCombinations2(nums);

    cout << results.size() ;
    cout << " [" ; for (auto s : results) cout << s << ", "; cout << ']' << endl;
}
