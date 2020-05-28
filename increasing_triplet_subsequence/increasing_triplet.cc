#include <iostream>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

// https://www.programcreek.com/2015/02/leetcode-increasing-triplet-subsequence-java/
bool increasingTriplet(vector<int>& nums) {
    int small = INT_MAX;
    int big = INT_MAX;
        
    for (auto n: nums) {
        if (n <= small) {
            small = n;
        } else if (n <= big) {
            big = n;
        } else {
            return true;
        }
    }

    return false;
}

void print_res(vector<int>& nums) {
    print_vector("nums", nums);
    cout << "increasingTriplet: " << (increasingTriplet(nums)? "True": "False") << endl;
}

int main() {
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {5,4,3,2,1};

    print_res(nums1);
    print_res(nums2);
}
