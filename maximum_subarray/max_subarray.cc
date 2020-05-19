#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int c = INT_MIN;
    int cur = 0;
    for (auto n : nums) {
        cur += n;
        c = max(c, cur);
        if (cur < 0) cur = 0;
    }
        
    return c;
}

void print_vector(string name, vector<int> &v) {
    cout << name << ": [";
    for (auto i: v) cout << i << ", ";
    cout << "]" << endl;
}

int main() {
    // vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    vector<int> nums = { 8,-19,5,-4,20 };
    print_vector("nums", nums);
    cout << "maxSubArray: " << maxSubArray(nums) << endl;
}
