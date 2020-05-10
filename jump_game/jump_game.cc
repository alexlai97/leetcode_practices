#include <vector>
#include <iostream>

using namespace std;

template <typename T>
ostream& operator<<(ostream &out, const vector<T>& v) {
    out << '[';
    for (auto n : v) out << n << ", ";
    out << ']';
    return out;
}

bool canJump(vector<int> &nums) {
    int len = nums.size();
    if (len <= 1) return true;

    int max = nums[0];

    for (int i = 0; i < len; ++i) {
        if (max <= i && nums[i] <= 0) {
            return false;
        }

        int tmp = i + nums[i];
        if (tmp > max) {
            max = tmp;
        }

        if (max >= len - 1) {
            return true;
        }
    }

    return false;
}



int main() {
    vector<int> nums1 = { 3,2,1,0,4 };
    vector<int> nums2 = { 0,2,4 };

    cout << (canJump(nums1)? "true":"false") << endl;
}
