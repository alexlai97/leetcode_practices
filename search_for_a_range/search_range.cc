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

vector<int> searchRange(vector<int>& nums, int target) {
    int len = nums.size();
    int i = 0, j = len-1;
    
    while (i < j) {
        int mid = i + (j-i)/2;

        if (nums[mid] < target) {
            i = mid+1;
        } else {
            j = mid;
        }
    }

    int first = j;

    if (i < len && nums[i] == target) {
        i = 0;
        j = len - 1;

        while (i < j) {
            int mid = i + (j-i+1)/2;

            if (nums[mid] > target) {
                j = mid-1;
            } else {
                i = mid;
            }
        }

        return vector<int> {first,j};
    } else {
        return vector<int> {-1,-1};
    }
    
}

vector<int> searchRange2(vector<int>& nums, int target) {
    int idxL=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    int idxU=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    if(idxL<nums.size() && nums[idxL]==target)
    {
        return {idxL,idxU-1};
    }else{
        return {-1,-1};
    }
}

void print_res(vector<int>& nums, int target) {
    print_vector("nums", nums);
    auto res = searchRange2(nums,target);
    cout << "target: " << target << endl;
    print_vector("searchRange", res);
}

int main() {
    vector<int> nums1 = {5,7,7,8,8,10};
    vector<int> nums2 = {2,2};
    print_res(nums1, 8);
    print_res(nums1, 6);
    print_res(nums2, 2);
}
