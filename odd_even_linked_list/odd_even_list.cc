#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ~ListNode() {
        delete this->next;
    }
};

void print_node(ListNode* n) {
    while (n) {
        cout << n->val << "->";
        n = n->next;
    }
    cout << "NULL" << endl;
}

ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;
    if (!head->next) return head;

    ListNode*cur = head;
    ListNode*odd = head;
    ListNode*even = head->next;
    ListNode* odd_prev = NULL;
    ListNode* even_prev = NULL;
    bool odd_flag = true;

    while (cur) {
        if (odd_flag) {
            if (odd_prev) odd_prev->next = cur;
            odd_prev = cur;
        } else {
            if (even_prev) even_prev->next = cur;
            even_prev = cur;
        }

        cur = cur->next;
        odd_flag = !odd_flag;
    }

    odd_prev->next = even;
    even_prev->next = NULL;

    return odd;
}

void print_res(string name, ListNode *n) {
    cout << name << endl;
    print_node(n);
    cout << "oddEvenList: " << endl;
    print_node(oddEvenList(n));
}


int main() {
    // 1->2->3->4->5->NULL
    ListNode *r1 = new ListNode(1,new ListNode(2,new ListNode(3,new ListNode(4,new ListNode(5)))));
    print_res("r1", r1);
    delete r1;

    // 2->1->3->5->6->4->7->NULL
    ListNode *r2 = new ListNode(2,new ListNode(1,new ListNode(3,new ListNode(5,new ListNode(6, new ListNode(4, new ListNode(7)))))));
    print_res("r2", r2);
    delete r2;
}
