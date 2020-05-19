#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void print_vector(string name, vector<int> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

int majorityElement(vector<int>& nums) {
    vector<pair<int,int>> table;
    sort(nums.begin(), nums.end());
    int prev;
    int count;
    for (int i = 0; i < nums.size(); ++i) {
        if (i == 0) {
            prev = nums[i];
            count = 1;
            continue;
        } else if (prev != nums[i]) {
            table.push_back(make_pair(prev,count));
            count = 1;
        } else {
            count ++;
        }
        prev = nums[i];
    }
    table.push_back(make_pair(prev,count));

    int max_count = INT_MIN;
    int max_num;
    for (int i = 0; i < table.size(); ++i) {
        if (table[i].second > max_count) {
            max_count = table[i].second;
            max_num = table[i].first;
        }
    }
    
    return max_num;
}

// stupid, but not sure why it works
int majorityElement2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

// Boyer-Moore Voting Algorithm
// still need to wrap my head around it
int majorityElement3(vector<int>& nums) {
    int count = 0;
    int candidate;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}

int main() {
    vector<int> nums = { 2,2,1,1,1,2,2 };
    auto result = majorityElement3(nums);
    print_vector("nums", nums);
    cout << "majorityElement: " << result << endl;
}
