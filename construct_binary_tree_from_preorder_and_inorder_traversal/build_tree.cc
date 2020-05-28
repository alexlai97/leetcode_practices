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

    ~TreeNode() {
        delete left;
        delete right;
    }
};

void print_vector(string name, vector<int> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

void printInorder(TreeNode* node)  {  
    if (node == nullptr) return;  
  
    printInorder(node->left);  
    cout<<node->val<<" ";  
    printInorder(node->right);  
}  

int search_index(vector<int>& arr, int start, int end, int key) {
    for (int i = start; i <= end; ++i) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
TreeNode* buildTree_helper(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd) {
    static int preIndex = 0;
    
    if (inStart > inEnd) return nullptr;

    // 1. pick an element from preorder
    // 2. increment the preIndex
    int pick_val = preorder[preIndex++];
    // 3. inIndex = find index in inorder
    int inIndex = search_index(inorder, inStart, inEnd, pick_val);

    // 4. construct aNode
    TreeNode * aNode = new TreeNode(pick_val);

    if (inStart == inEnd) return aNode;

    // 5. aNode->left = buildTree_helper(inStart, inIndex -1)
    aNode->left = buildTree_helper(preorder, inorder, inStart, inIndex -1);
    // 6. aNode->right = buildTree_helper(inIndex+1, inEnd)
    aNode->right = buildTree_helper(preorder, inorder, inIndex+1, inEnd);

    return aNode;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
    return buildTree_helper(preorder,inorder, 0,preorder.size()-1);
}

int main() {
    // vector<int> preorder = {3,9,20,15,7};
    // vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {1,2};
    vector<int> inorder = {2,1};
    TreeNode* root = buildTree(preorder, inorder);
    printInorder(root);
    cout << endl;

    delete root;
}
