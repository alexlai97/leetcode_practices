#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    int result = 0;
    int p_min = prices[0];

    for (int i = 1; i < prices.size(); ++i) {
        result = max(result, prices[i] - p_min);
        p_min = min(p_min, prices[i]);
    }

    return result;
}

int main() {
    vector<int> prices = { 7,1,5,3,6,4 };
    int result = maxProfit(prices);

    cout << "maxProfit( [";
    for (auto p : prices) cout << p << ", ";
    cout << "] ) = " << result << endl;
}
