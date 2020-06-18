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

void moveZeroes(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len = nums.size();
    int i = 0;
    int j = 0;
    while (i < len) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
        i++;
    }
    fill(nums.begin()+j,nums.end(),0);
}

void print_res(vector<int>& nums) {
    print_vector("nums", nums);
    moveZeroes(nums);
    print_vector("nums", nums);
}

int main() {
    vector<int> nums = { 0,1,0,3,12 };
    print_res(nums);
}
