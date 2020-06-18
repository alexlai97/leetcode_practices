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

int singleNumber(vector<int>& nums) {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    if (nums.size() == 1) return nums[0];
    auto it = nums.begin();
    int res = *it;
    ++it;
    for (;it != nums.end(); ++it) 
        res ^= *it;

    return res;
}

void print_res(vector<int>& nums) {
    int res = singleNumber(nums);
    print_vector("nums", nums);
    cout << "single number: " << res << endl;
}

int main() {
    vector<int> nums1 = {4,1,2,1,2};
    print_res(nums1);
}
