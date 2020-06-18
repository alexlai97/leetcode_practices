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

vector<int> plusOne(vector<int>& digits) {
    vector<int> res = digits;
    bool carry = false;
    for (auto rit = res.rbegin(); rit != res.rend(); ++rit) {
        if (carry || rit == res.rbegin()) {
            *rit += 1;
        } else {
            break;
        }

        if (*rit == 10) {
            *rit = 0;
            carry = true;
        } else {
            carry = false;
        }
    }

    if (carry)  
        res.insert(res.begin(),1); // inefficent, but who cares..

    return res;
}

void print_res(vector<int>& digits) {
    print_vector("before", digits);
    auto res = plusOne(digits);
    print_vector("after", res);
}

int main() {
    vector<int> d1 = {1,0,9};
    vector<int> d2 = {2,9,9};
    vector<int> d3 = {9,9,9};
    print_res(d1);
    print_res(d2);
    print_res(d3);
}
