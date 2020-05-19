#include <iostream>
#include <vector>
#include <string>

using namespace std;


void print_vector(string name, vector<int> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

void print_result(string name, vector<vector<int>>&result) {
    cout << name << ": {" << endl;
    for (auto i : result) {
        print_vector("",i);
    }
    cout << "}" << endl;
}

// did not quite understand
void backtrack(vector<vector<int>> &ans, vector<int> &nums, vector<int> cur, int first, int k) {
    if (cur.size() == k) {
        ans.emplace_back(cur);
        return;
    }

    for (int i = first; i < nums.size();++i) {
        cur.emplace_back(nums[i]);
        backtrack(ans,nums,cur,i+1,k);
        cur.pop_back();
    }
}

// backtracking
vector<vector<int>> subsets2(vector<int>& nums) {
    vector<vector<int>> ans;
    if (!nums.empty())  {

        for (int k = 0; k <= nums.size(); ++k) {
            backtrack(ans,nums,vector<int>(),0,k);
        }
    }
    return ans;
}


vector<int> translate(int n, vector<int>&nums) {
    vector<int> res;
    for (int i = 1, j=0; i < (1 << nums.size()); i*=2, ++j) {
        if (n & i) res.emplace_back(nums[j]);
    }
    return res;
}

vector<vector<int>> subsets(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int>> ans;
    if (!nums.empty()) {
        for (int i = 0; i < (1 << len); ++i) {
            ans.emplace_back(translate(i,nums));
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    print_vector("nums", nums);
    auto result = subsets2(nums);
    print_result("res", result);
}
