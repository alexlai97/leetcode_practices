#include <iostream>
#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}

    ~Node() {
        delete left;
        delete right;
    }
};

void preoreder_print(Node* node, bool with_next) {
    if (!node) return;
    cout << node->val << ", "; 
    if (with_next) { 
        cout << "(";
        if (node->next) {
            cout << node->next->val;
        } else {
            cout << "#";
        }
        cout << "), ";
    }
    preoreder_print(node->left, with_next);
    preoreder_print(node->right, with_next);
}


void reversed_postorder_print(Node* node, bool with_next, int level) {
    if (!node) return;
    reversed_postorder_print(node->right, with_next, level+1);
    reversed_postorder_print(node->left, with_next, level+1);
    cout << node->val << "[" << level << "]"<<  ", "; 
    if (with_next) { 
        cout << "(";
        if (node->next) {
            cout << node->next->val;
        } else {
            cout << "#";
        }
        cout << "), ";
    }
}

void reverse_postorder_connect(vector<Node*> &level_dict,Node *node, int level) {
    if (!node) return ;
    if (level >= level_dict.size()) level_dict.push_back(nullptr);

    reverse_postorder_connect(level_dict, node->right, level+1);
    reverse_postorder_connect(level_dict, node->left, level+1);

    node->next = level_dict[level];
    level_dict[level] = node;
}

// my solution
Node* connect(Node* root) {
    vector<Node*> level_dict;
    reverse_postorder_connect(level_dict, root, 0);
    return root;
}

// other people's solution after my submission
// it works because it was given **perfect** binary tree 
Node* connect2(Node* root) {
    if(root==nullptr) return root;
    if(root->left!=nullptr){
        root->left->next =root->right;            
    }
    if(root->right!=nullptr && root->next!=nullptr){
        root->right->next = root->next->left;            
    }
    root->left = connect2(root->left);
    root->right = connect2(root->right);
    return root;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    connect2(root);
    preoreder_print(root, true); cout << endl;
    // reversed_postorder_print(root, true, 0); cout << endl;

    delete root;
}
