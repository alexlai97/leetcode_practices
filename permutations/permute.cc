#include <iostream>
#include <vector>

using namespace std;
void print_vector(string name, vector<int> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

void print_vec_vec(string name, vector<vector<int>>&vec_vec) {
    cout << name << ": {" << endl;
    for (auto i : vec_vec) {
        print_vector("",i);
    }
    cout << "}" << endl;
}

void backtrack(vector<vector<int>> &ans, vector<int> cur, vector<int> avail) {
    if (avail.empty()) {
        ans.push_back(cur);
        return;
    }
    for (int i=0; i < avail.size(); ++i) {
        vector<int> new_cur = cur;
        new_cur.push_back(avail[i]);
        vector<int> new_avail = avail;
        new_avail.erase(new_avail.begin()+i);
        backtrack(ans,new_cur,new_avail);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    if (!nums.empty()) {
        backtrack(ans,vector<int>(), nums);
    }
    return ans;
}

// faster solution
void bt( vector<int>& nums, int start, vector<vector<int>>& res ) {
    if( start == nums.size() ) {
        res.push_back( nums );
        return;
    }
    for( int i = start; i < nums.size(); ++i ) {
        swap( nums[start], nums[ i ] );
        bt( nums, start+1, res );
        swap( nums[start], nums[ i ] );
    }
}

vector<vector<int>> permute2(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> res;
    bt( nums, 0, res );
    return res;
}

int main() {
    vector<int> nums = { 1,2,3 };
    auto result = permute2(nums);
    print_vector("nums", nums);
    print_vec_vec("permute", result);
}
