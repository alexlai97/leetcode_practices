#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());

    return nums[nums.size()-k];
}

void print_res(vector<int>& nums, int k) {
    int res = findKthLargest(nums,k);
    print_vector("nums", nums);
    cout << "findKthLargest: " << res << endl;
}

int main() {
    vector<int>nums1 = { 3,2,1,5,6,4 } ;
    vector<int>nums2 = {3,2,3,1,2,4,5,5,6};
    print_res(nums1,2);
    print_res(nums2,4);
}
