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

int removeDuplicates(vector<int>& nums) {
    int len = nums.size();
    int i = 0,j = 0;
    while (i < len - 1) {
        while (i < len - 1 && nums[i] == nums[i+1]) {
            i++;
        }

        nums[j] = nums[i];
        j++;
        i++;
    }

    if (i != len) {
        nums[j] = nums[i];
        j++;
    }
    return j;
}

void print_res(vector<int>& nums) {
    print_vector("before", nums);
    int res = removeDuplicates(nums);
    cout << "len: " << res << endl;
    print_vector("after", nums);
}

int main() {
    vector<int> nums1 = { 0,0,1,1,1,2,2,3,3,4 };
    vector<int> nums2 = { 0,0,1,1,1};
    vector<int> nums3 = { 0 };
    vector<int> nums4 = { };
    print_res(nums1);
    print_res(nums2);
    print_res(nums3);
    print_res(nums4);
}
