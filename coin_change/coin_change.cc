#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // sort coins in decending order
    sort(coins.begin(), coins.end(), greater<int>());

    if (amount < 0) {
        return -1;
    } else if (amount == 0) {
        return 0;
    }

    int table[amount+1];
    table[0] = 0;
    
    for (int v = 1; v <= amount; ++v) {
        int min_num = -1; // -1 means +infinity

        // loop through coins in decending order
        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] > v) continue;

            int tmp = table[v - coins[i]];
            if (tmp == -1) {
               // min_num = min_num 
            } else if (min_num == -1) {
               min_num = tmp + 1; 
            } else {
               min_num = (min_num < tmp + 1)? min_num : (tmp + 1); 
            }
        }

        table[v] = min_num;
    }

    // cout << "table: ";
    // for (auto t: table) cout << t << ", ";
    // cout << endl;
        
    return table[amount];
}

int main() {
    vector<int> coins = { 2  };
    int amount = 3;
    int result = coinChange(coins, amount);

    cout << "coinChange( [";
    for (auto c : coins) cout << c << ", " ;
    cout << " ], " << amount;
    cout << " )" << " = " << result << endl;
}
