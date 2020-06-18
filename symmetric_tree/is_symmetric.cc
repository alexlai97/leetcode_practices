#include <iostream>
#include <stack>
#include <queue>
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

bool compare_recursive(TreeNode *r1, TreeNode *r2) {
    if (!r1 && !r2) {
        return true;
    } else if (!r1 ^ !r2) {
        return false;
    } else if (r1->val != r2->val) {
        return false;
    }

    return compare_recursive(r1->left,r2->right) && compare_recursive(r1->right, r2->left);
}

bool isSymmetric_recursive(TreeNode* root) {
    if (!root) return true;
    return compare_recursive(root->left, root->right);
}

bool isSymmetric_iterative(TreeNode* root) {
    if (!root) return true;
    queue<TreeNode*> q;
    q.push(root);
    q.push(root);

    while (!q.empty()) {
        TreeNode *n1 = q.front();
        q.pop();
        TreeNode *n2 = q.front();
        q.pop();
        if (!n1 && !n2) continue;
        if (!n1 || !n2) return false;
        if (n1->val != n2->val) return false;

        q.push(n1->left);
        q.push(n2->right);
        q.push(n1->right);
        q.push(n2->left);
    }

    return true;
}

void print_res(TreeNode* root) {
    cout << "isSymmetric: " << (isSymmetric_iterative(root)? "True": "False") << endl;
}

int main() {
    TreeNode *r1 = new TreeNode(1,
            new TreeNode(2,
                new TreeNode(3),
                new TreeNode(4)),
            new TreeNode(2,
                new TreeNode(4),
                new TreeNode(3)
                ));
    TreeNode *r2 = new TreeNode(1,
            new TreeNode(2,
                nullptr,
                new TreeNode(3)),
            new TreeNode(2,
                nullptr,
                new TreeNode(3)
                ));
    TreeNode *r3 = new TreeNode(1,
            nullptr,
            new TreeNode(2));

    print_res(r1);
    print_res(r2);
    print_res(r3);


    delete r1;
    delete r2;
    delete r3;
}


