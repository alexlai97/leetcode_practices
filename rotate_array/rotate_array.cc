#include <iostream>
#include <algorithm>
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

void rotate(vector<int>& nums, int k) {
    if (k == 0) return;
    k %=  nums.size();
    reverse(nums.begin(), nums.end()); 
    reverse(nums.begin(),nums.begin()+k);
    reverse(nums.begin()+k,nums.end());
}

void print_res(vector<int>& nums, int k) {
    cout << "k: " << k << endl;
    print_vector("before", nums);
    rotate(nums,k);
    print_vector("after", nums);
}

int main() {
    vector<int> nums = { 1,2,3,4,5,6,7 };
    print_res(nums,3);
    print_res(nums,0);
}
