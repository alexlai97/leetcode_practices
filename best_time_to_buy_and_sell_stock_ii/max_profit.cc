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

int maxProfit(vector<int>& prices) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int len = prices.size();
    int ans = 0;
    for (int i = 0; i < len - 1; i++) {
        if (prices[i] < prices[i+1])
            ans+=prices[i+1]-prices[i];
    }
    return ans;
}


void print_res(vector<int>& prices) {
    print_vector("prices", prices);
    int res = maxProfit(prices);
    cout << "maxProfit: " << res << endl;
}

int main() {
    vector<int> ps1 = {1,2,3,4,5};
    vector<int> ps2 = {7,1,5,3,6,4};
    vector<int> ps3 = {7,6,4,3,1};

    print_res(ps1);
    print_res(ps2);
    print_res(ps3);
}
