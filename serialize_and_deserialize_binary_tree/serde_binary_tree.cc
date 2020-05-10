#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

    ~TreeNode() {
        delete left;
        delete right;
    }
};
bool compare_node(TreeNode *a, TreeNode *b) {
    if (a == NULL && b == NULL) return true;
    if (a == NULL && b != NULL) return false;
    if (b == NULL && a != NULL) return false;
    if (a->val != b->val) return false;
    if (!compare_node(a->left, b->left)) return false;
    if (!compare_node(a->right, b->right)) return false;
    return true;
}

/*
class Codec {
private:
    string serialize_node(TreeNode *node) {
        string result;
        if (node == NULL) {
            result.append("null,");
            return result;
        } 
        result.append(to_string(node->val));
        result.push_back(',');
        result.append(serialize_node(node->left));
        result.append(serialize_node(node->right));
        return result;
    }

    TreeNode *deserialize_helper(vector<string> &tokens, int &i) {
        if (tokens[i] == "null") return NULL;

        TreeNode *root = new TreeNode(stoi(tokens[i]));

        i+=1;
        root->left = deserialize_helper(tokens,i);
        i+=1;
        root->right = deserialize_helper(tokens,i);

        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        result.append("[");
        
        result.append(serialize_node(root));

        result.append("]");
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        int last = 1;
        int next = 0;
        vector<string> tokens;

        while ( (next = data.find(',', last)) != string::npos ) { 
            string token = data.substr(last, next - last);

            tokens.emplace_back(token);

            last = next + 1;
        }

        int i = 0;
        return deserialize_helper(tokens, i);
    }

};
*/

class Codec {
public:
    char token = ' ';
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }
    void serialize(TreeNode* root, ostringstream& oss) {
        if (root == nullptr) {
            oss << "#" << token;
            return;
        }
        oss << to_string(root->val) << token;
        serialize(root->left, oss);
        serialize(root->right, oss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize(iss);
    }
    
    TreeNode* deserialize(istringstream& iss) {
        string str;
        iss >> str;
        if (!str.compare("#")) return nullptr;
        TreeNode* root = new TreeNode(stoi(str));
        TreeNode* left = deserialize(iss);
        TreeNode* right = deserialize(iss);
        root->left = left;
        root->right = right;
        return root;
        
    }
};


int main() {
    TreeNode * left4 = new TreeNode (4) ;
    TreeNode * right5 = new TreeNode (5) ;
    TreeNode * left = new TreeNode (2) ;
    TreeNode * right = new TreeNode (3) ;
    right->left = left4;
    right->right = right5;
    TreeNode * root = new TreeNode(1);
    root->left = left;
    root->right = right;

    Codec codec;

    string serialized_tree = codec.serialize(root);
    cout << "serialized_tree: " << serialized_tree << endl;
    TreeNode * new_tree = codec.deserialize(serialized_tree);
    cout << "new_tree: " << codec.serialize(new_tree) << endl;

    cout << "comparing: " << (compare_node(root, new_tree)? "True":"False") << endl;

    delete root;
    delete new_tree;
}
