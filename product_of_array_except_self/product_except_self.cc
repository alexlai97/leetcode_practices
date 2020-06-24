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

// speed up code
static auto x = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty()) return vector<int>();
    vector<int> L(nums.size(),1);
    if (nums.size()==1) return L;

    for (int i = 0; i < nums.size()-1; ++i) {
        L[i+1] = L[i] * nums[i];
    }

    int R_prod = 1;
    for (int i = nums.size()-2; i >= 0;--i) {
        R_prod *= nums[i+1];
        L[i] *= R_prod;
    }

    return L;
}

void print_res(vector<int>& nums) {
    auto res = productExceptSelf(nums);
    print_vector("nums",nums);
    print_vector("productExceptSelf",res);
}

int main() {
    vector<int> nums1 = {1,2,3,4};
    print_res(nums1);
}
