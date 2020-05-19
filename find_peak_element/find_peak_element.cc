#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int len = nums.size();
    int l = 0, r = len-1;

    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid+1]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

void print_res(vector<int>& nums) {
    print_vector("nums", nums);

    cout << "findPeakElement: " << findPeakElement(nums) << endl;
}

int main() {
    vector<int> n1 = {1,2,3,1};
    print_res(n1);
    vector<int> n2 = {1,2,1,3,5,6,4};
    print_res(n2);
}

