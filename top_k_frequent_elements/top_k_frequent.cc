#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>          // std::priority_queue
using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

struct compare { 
    bool operator()(pair<int, int> p1, pair<int, int> p2) 
    { 
        if (p1.second == p2.second) 
            return p1.first < p2.first; 

        return p1.second < p2.second;     
    } 
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    if (nums.empty() || k <= 0 || k > nums.size()) return res;

    unordered_map<int,int> mp;

    for (auto n: nums) {
        mp[n]++;
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq(mp.begin(), mp.end());

    for (int i =0; i < k; ++i) {
        res.push_back(pq.top().first);
        pq.pop();
    }
        
    return res;
}

void print_res(vector<int>&nums, int k) {
    vector<int> res = topKFrequent(nums,k);
    print_vector("nums: ", nums);
    cout << "k: " << k << endl;
    print_vector("topKFrequent: ", res);
}

int main() {
    vector<int> nums1 {1,1,1,2,2,3};
    print_res(nums1, 3);
    vector<int> nums2 {1};
    print_res(nums2, 1);
}
