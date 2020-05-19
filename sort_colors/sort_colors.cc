#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

void sortColors2(vector<int>& nums) {
    int table[3] = {0};
    for (auto n: nums) {
        table[n]++;
    }
    int j = 0;
    for (int i = 0; i < 3; ++i) {
        for (int c = 0; c < table[i]; ++c) {
            nums[j] = i;
            j++;
        }
    }
}

void sortColors(vector<int>& nums) {
    map<int,int> mp;
    for (auto n: nums) {
        if (mp.find(n) == mp.end()) {
            mp[ n ] = 1;
        } else {
            mp.at(n) += 1;
        }
        // cout << "n: " << n << ", mp[n]: "<< mp[n] << endl;
    }

    int j = 0;
    for (auto &x: mp) {
        for (int i = 0; i < x.second; ++i) {
            nums[j] = x.first;
            j++;
        }
    }
}

void print_res(vector<int>& nums) {
    print_vector("before", nums);

    sortColors2(nums);
    print_vector("after", nums);
}

int main() {
    vector<int>nums1 = {2,0,2,1,1,0} ;
    print_res(nums1);
    vector<int>nums2 = {1} ;
    print_res(nums2);
    vector<int>nums4 = {2,0} ;
    print_res(nums4);
}
