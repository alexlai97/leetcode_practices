#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}


// one pass using hashtable
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> indicies = { -1, -1 };
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i) {
        int cur = nums[i];
        int counter = target - cur;
        if (mp.count(counter) != 0) {
            indicies[0] = mp[counter];
            indicies[1] = i;
            break;
        } else {
            mp[nums[i]] = i;
        }
    }
    return indicies;
}

void print_res(vector<int>& nums, int target) {
    vector<int> res = twoSum(nums, target);
    print_vector("nums", nums);
    cout << "twoSum indices: " << "[" << res[0] << ", " << res[1] << "]" << endl;
}

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    print_res(nums1,18);
    print_res(nums1,9);
    print_res(nums1,26);
}
