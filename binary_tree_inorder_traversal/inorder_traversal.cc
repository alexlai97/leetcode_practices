#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void print_vector(string name, vector<int> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> tree_stack;

    TreeNode *cur = root;
    while (cur || !tree_stack.empty()) {
        while (cur) {
            tree_stack.push(cur);
            cur = cur->left;
        }
        
        cur = tree_stack.top();
        tree_stack.pop();
        res.push_back(cur->val);
        cur = cur->right;
    }
    return res;
}

void print_res(string name, TreeNode*n) {
    cout << "inorderTraversal: " << endl;
    auto res = inorderTraversal(n);
    print_vector(name, res);
}


int main() {
    TreeNode *t1 = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    print_res("t1",t1);

}
