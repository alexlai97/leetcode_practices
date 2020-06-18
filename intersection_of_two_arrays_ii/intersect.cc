#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    sort(nums1.begin(),nums1.end());
    sort(nums2.begin(),nums2.end());

    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while (true) {
        if (it1 == nums1.end() || it2 == nums2.end()) {
            break;
        }
        if (*it1 == *it2) {
            ans.push_back(*it1);
            it1++;
            it2++;
        } else if (*it1 > *it2) {
            it2++;
        } else {
            it1++;
        }
    }

    return ans;
}

void print_res(vector<int> nums1, vector<int> nums2) {
    print_vector("nums1",nums1);
    print_vector("nums2",nums2);
    vector<int> res = intersect(nums1,nums2);
    print_vector("res",res);
}

int main() {
    print_res(vector<int>{1,2,2,1}, vector<int>{2,2});
    print_res(vector<int>{4,9,5}, vector<int>{9,4,9,8,4});
}
