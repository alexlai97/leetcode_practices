#include <iostream>
#include <stack>
#include <climits>
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

bool inorder_traversal(TreeNode*root, long* last_value) {
    if (root->left) {
        if (!inorder_traversal(root->left, last_value)) {
            return false;
        }
    }
    if (root->val <= *last_value) {
        return false;
    } else {
        *last_value = root->val;
    }
    if (root->right) {
        if (!inorder_traversal(root->right, last_value)) {
            return false;
        }
    }
    return true;
}

bool isValidBST(TreeNode* root) {
    if (!root) return true;
    long value = LONG_MIN;
    return inorder_traversal(root, &value);
}

int main() { 
    TreeNode *r1 = new TreeNode(2,new TreeNode(1), new TreeNode(3));
    cout << (isValidBST(r1)? "True" : "False")  << endl;
    TreeNode *r2 = new TreeNode(10,new TreeNode(5), new TreeNode(15, 
                new TreeNode(6), new TreeNode(20)));
    cout << (isValidBST(r2)? "True" : "False")  << endl;
    delete r1;
    delete r2;
}
