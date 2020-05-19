#include <iostream>
#include <vector>

using namespace std;

void print_vector(string name, vector<int> &v) {
    cout << name << ": [";
    for (auto i: v) cout << i << ", ";
    cout << "]" << endl;
}

// merge into nums1
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> nums1_copy {nums1};
    
    int i = 0;
    int j = 0;
    int k = 0;
    while ( i < m || j < n ) {
        if (j >= n || (i < m && nums1_copy[i] < nums2[j])) {
            nums1[k] = nums1_copy[i];
            i++;
        } else {
            nums1[k] = nums2[j];
            j++;
        }
        k++;
    }

}

int main() {
    vector<int> nums1 = { 1,2,3,0,0,0 }; 
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;
    
    print_vector("nums1: ", nums1);
    cout << "m: " << m << endl;
    print_vector("nums2: ", nums2);
    cout << "n: " << n << endl;

    merge(nums1,m,nums2,n);

    print_vector("nums1: ", nums1);
}
