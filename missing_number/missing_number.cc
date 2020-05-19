#include <iostream>
#include <vector>

using namespace std;

// using XOR operator , ticky!
int missingNumber1(vector<int>& nums) {
    int missing = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
        missing ^= i ^ nums[i];
    }

    return missing;
}

// expected sum - actual sum
int missingNumber2(vector<int>& nums) {
    int expectedSum = nums.size() * (nums.size() + 1) /2 ;
    int actualSum = 0;
    for (auto n : nums) actualSum+= n;

    return expectedSum-actualSum;
}

void print_vector(string name, vector<int> &v) {
    cout << name << ": [";
    for (auto i: v) cout << i << ", ";
    cout << "]" << endl;
}

int main() {
    vector<int> nums = { 9,6,4,2,3,5,7,0,1 };
    print_vector("nums", nums);
    cout << "missing: " << missingNumber2(nums) << endl;

}
