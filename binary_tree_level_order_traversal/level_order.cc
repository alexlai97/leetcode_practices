#include <iostream>
#include <vector>
#include <queue>

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

void print_res(string name, TreeNode*n) {
    cout << "levelOrder: " << endl;
    auto res = levelOrder(n);
    print_vec_vec(name, res);
}

int main() {
    TreeNode *t1 = new TreeNode(3, new TreeNode(9), 
            new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    print_res("t1",t1);

    delete t1;
}
