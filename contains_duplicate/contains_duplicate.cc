#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}


bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto n: nums) {
        if (s.count(n)!=0) return true;
        s.insert(n);
    }
    return false;
}

void print_res(vector<int>& nums) {
    print_vector("nums", nums);
    bool res = containsDuplicate(nums);
    cout << "containsDuplicate: " << (res? "T":"F") << endl;
}

int main() {
    vector<int> ns1 = {1,2,3,4};
    vector<int> ns2 = {1,2,3,1};
    vector<int> ns3 = {1,1,1,3,3,4,3,2,4,2};
    print_res(ns1);
    print_res(ns2);
    print_res(ns3);
}
