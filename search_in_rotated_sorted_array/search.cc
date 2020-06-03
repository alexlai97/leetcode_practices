#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

// https://leetcode.wang/leetCode-33-Search-in-Rotated-Sorted-Array.html?h=search
int search(vector<int>& nums, int target) {
    int len = nums.size();
    int start = 0;
    int end = len - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > nums[end]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    int bias = start;
    // cout << "bias: " << bias << endl;

    start = 0;
    end = len - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        int unbiased_mid = (mid + bias) % len;
        int val = nums[unbiased_mid];
        // cout << "start: " << start << ", end: " << end 
        //     << ", mid: " << mid << ", unbiased_mid: " << unbiased_mid << endl;
        if (target == val) {
            return unbiased_mid;
        } else if (target < val) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;
}

void print_res(vector<int>& nums, int target) {
    print_vector("nums", nums);
    cout << "target: " << target << endl;
    int res = search(nums, target);
    cout << ", index: " << res << endl;
}

int main() {

    vector<int> nums1 = {4,5,6,7,0,1,2};
    print_res(nums1, 0);
    vector<int> nums2 = {1,3};
    print_res(nums2, 2);
    print_res(nums1, 1);
    print_res(nums1, 2);
    print_res(nums1, 3);
}
