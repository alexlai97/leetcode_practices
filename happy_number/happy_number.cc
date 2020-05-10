#include <iostream>
#include <vector>
#include <assert.h>
#include <unordered_set>

using namespace std;

/*
vector<int> n2vec_rev(int n) {
    assert(n >= 0);
    vector<int> result;

    if (n == 0) return vector<int> { 0 };

    while (n != 0) {
        result.emplace_back(n % 10);
        n = n / 10;
    }

    return result;
}

bool isHappy(int n) {
    vector<int> vec_rev = n2vec_rev(n);
    unordered_set<int> myset;

    while (n != 1) {
        myset.insert(n); 

        int sum = 0;
        for (auto it = vec_rev.rbegin(); it != vec_rev.rend(); ++it) {
            sum += *it * *it;
        }
        // cout << sum << endl;
        if (sum == 1) return true;
        if (myset.find(sum) != myset.end()) return false;

        n = sum;
        vec_rev = n2vec_rev(n);
    }
    return true;
}
*/

int f(int n) {
    int sum = 0;
    int digit;
    while (n != 0) {
        digit = n % 10;
        n = n / 10;
        sum += digit * digit;
    }

    return sum;
}

bool isHappy(int n) {
    unordered_set<int> myset;

    while (n != 1) {
        myset.insert(n);
        n = f(n);
        if (myset.find(n) != myset.end()) return false;
    }

    return true;
}

int main() {
    int n = 19;
    // vector<int> vec = n2vec_rev(n);
    // cout << "n2vec_rev(" << n<< "): ["; for (auto i : vec) cout << i << ", "; cout << "]"<< endl;
    cout << "isHappy("<<n<<"): " << (isHappy(n)? "Happy":"Not happy") << endl;
}
