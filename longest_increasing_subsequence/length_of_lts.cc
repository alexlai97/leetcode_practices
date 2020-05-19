#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(string name, vector<int> &v) {
    cout << name << ": [";
    for (auto i: v) cout << i << ", ";
    cout << "]" << endl;
}

int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int table[nums.size()];
    table[0]=1;
    int max_table = table[0];
    for (int i = 1; i < nums.size(); ++i) {
        int max=1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                int cur = table[j]+1;
                if (cur > max) max = cur;
            }
        }
        table[i] = max;
        // cout << "nums["<< i<<"]: " << nums[i] <<  "| table[i]: " << table[i]  << endl;
        if (table[i] > max_table) max_table = table[i];
    }
    return max_table;
}

// other's solution
// very clever
int lengthOfLIS2(vector<int>& nums) {
    vector<int> res;
    for (auto n:nums){
        auto it = lower_bound(res.begin(), res.end(), n);
        if (it == res.end()) {
            res.push_back(n);
        } else {
            *it = n;
        }
    }
    print_vector("res",res);

    return res.size();
}


int main() {
    vector<int> nums = { 1,3,6,7,9,4,10,5,6 };
    // vector<int> nums = {10,9,2,5,3,7,101,18};
    int res = lengthOfLIS2(nums);
    print_vector("nums", nums);
    cout << "lengthOfLIS: " << res << endl;
}
