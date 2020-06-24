#include <iostream>
#include <vector>
#include <algorithm>    // std::min
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}


int rob(vector<int>& nums) {
    int a,b,c,d;
    if (nums.size() == 0) {
        return 0;
    } else if (nums.size() == 1) {
        return nums[0];
    } else if (nums.size() == 2) {
        return max(nums[0],nums[1]);
    }

    a = nums[0];
    b = nums[1];
    c = max(a+nums[2],b);
    if (nums.size() == 3) return c;

    d = max({a+nums[2],b+nums[2],c});

    for (int i = 3; i < nums.size(); ++i) {
        d = max({a+nums[i],b+nums[i],c});

        a = b;
        b = c;
        c = d;
    }

    return d;
}

void print_res(vector<int>& nums) {
   print_vector("nums", nums);
   cout << "can rob $" << rob(nums) << endl;
}

int main() { 
    vector<int> nums1 = {1,2,3,1};
    vector<int> nums2 = {2,7,9,3,1};
    vector<int> nums3 = {2,1,1,2};

    print_res(nums1);
    print_res(nums2);
    print_res(nums3);
}
