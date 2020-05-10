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

int main() {
    string nums = "279";
    vector<string> results = letterCombinations(nums);

    cout << results.size() ;
    cout << " [" ; for (auto s : results) cout << s << ", "; cout << ']' << endl;
}
