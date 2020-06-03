#include <iostream>
#include <stack>
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

void inorder_print(TreeNode* node) {
    if (!node) return;
    inorder_print(node->left);
    cout << node->val << ", ";
    inorder_print(node->right);
}

int kthSmallest(TreeNode* root, int k) {
    TreeNode *cur = root;
    stack<TreeNode*> st;

    while (true) {
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }

        cur = st.top();
        st.pop();

        if (--k == 0) return cur->val;

        cur = cur->right;
    }
}

void print_res(TreeNode* root, int k) {
    int res = kthSmallest(root, k);
    inorder_print(root); cout << endl;
    cout << "k: " << k << "th smallest: " << res << endl;
}

int main() {
    TreeNode* root = new TreeNode(5,
                                  new TreeNode(3,
                                               new TreeNode(2,
                                                            new TreeNode(1),
                                                            nullptr),
                                               new TreeNode(4)),
                                  new TreeNode(6));



    print_res(root,6);

    delete root;
}
