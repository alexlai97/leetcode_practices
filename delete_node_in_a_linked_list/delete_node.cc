#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ~ListNode() {
        delete this->next;
    }
};
void print_node(string name, ListNode* n) {
    cout << name << ": ";
    while (n) {
        cout << n->val << "->";
        n = n->next;
    }
    cout << "NULL" << endl;
}

// stupid question
void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

void print_res(ListNode *node) {
    print_node("before", node);
    deleteNode(node);
    print_node("after", node);
}

int main() {
    // [4,5,1,9]
    ListNode* root = new ListNode(4,new ListNode(5,new ListNode(1,new ListNode(9))));
    print_res(root);

    delete root;
}
