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

// solution from https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/discuss/638633/Beautiful-C%2B%2B-(Use-two-deque)
// indeed beautiful
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;

    if (root == nullptr)
        return result;

    deque<TreeNode*> ancestors;

    ancestors.push_front(root);

    bool forwards = true;

    while (ancestors.size() > 0)
    {
        // Get the values of each node, in the required order
        vector<int> vals;
        if (forwards)
            for (auto it = ancestors.begin(); it != ancestors.end(); ++it)   
                vals.push_back((*it)->val);
        else // (backwards)
            for (auto it = ancestors.rbegin(); it != ancestors.rend(); ++it)
                vals.push_back((*it)->val);
        result.push_back(vals);

        // Identify Descendants
        deque<TreeNode*> descendants;
        for (auto& ancestor : ancestors)
        {
            if (ancestor->left != nullptr)
                descendants.push_back(ancestor->left);
            if (ancestor->right != nullptr)
                descendants.push_back(ancestor->right);
        }

        // Prepare for next level
        ancestors = descendants; // Descendents Become Ancestors for next level
        forwards = !forwards; // Reverse direction for next level    
    }

    return result;
}

void print_res(string name, TreeNode*n) {
    cout << "zigzagLevelOrder: " << endl;
    auto res = zigzagLevelOrder(n);
    print_vec_vec(name, res);
}

int main() {
    TreeNode *t1 = new TreeNode(3, new TreeNode(9), 
            new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    print_res("t1",t1);

    delete t1;
}
