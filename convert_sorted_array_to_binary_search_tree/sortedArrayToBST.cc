#include <iostream>
#include <sstream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

TreeNode* helper(vector<int>& nums, int start, int end) {
    if (end < start) {
        return nullptr;
    } else if (end == start) {
        return new TreeNode(nums[start]);
    }

    int mid = (start + end) / 2;
    return new TreeNode(nums[mid],
            helper(nums, start, mid - 1),
            helper(nums, mid + 1, end));
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size()-1);
}

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

template <typename T>
void print_vec_vec(string name, vector<vector<T>>&vec_vec) {
    cout << name << ": {" << endl;
    for (auto i : vec_vec) {
        print_vector("",i);
    }
    cout << "}" << endl;
}

// fast but not space efficient
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;

    deque<TreeNode*> ancestors;
    ancestors.push_front(root);
    
    while (ancestors.size() > 0) {
        vector<int> vals;
        for (auto t : ancestors) {
            vals.push_back(t->val);
        }
        result.push_back(vals);

        deque<TreeNode*> descendants;
        for (auto t: ancestors) {
            if (t->left) descendants.push_back(t->left);
            if (t->right) descendants.push_back(t->right);
        }

        ancestors = descendants;
    }

    return result;
}

void print_res(vector<int>& nums) {
    print_vector("nums",nums);
    TreeNode* r = sortedArrayToBST(nums);
    auto vv = levelOrder(r);
    print_vec_vec("levelOrder: ", vv);
    delete r;
}

int main() {
    vector<int> nums1 = {-10,-3,0,5,9};
    print_res(nums1);
}
