#include <string>
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* p1 = dummy;
    ListNode* p2 = dummy;

    for (int i = 0; i < n+1; ++i) {
        if (p1 == nullptr) return head;
        p1 = p1->next;
    }

    while (p1) {
        p1 = p1->next;
        p2 = p2->next;
    }

    ListNode* tmp = p2->next;
    p2->next = tmp->next;
    tmp->next = nullptr;
    delete tmp;

    return dummy->next;
}

void print_res(ListNode* head, int n) {
    cout << "n: " << n << endl;
    print_node("before", head);
    head = removeNthFromEnd(head,n);
    print_node("after", head);
}

int main() {

    ListNode *r1 = new ListNode(1,
            new ListNode(2,
                new ListNode(3,
                    new ListNode(4,
                        new ListNode(5)))));
    print_res(r1,2);
    delete r1;

    ListNode *r2 = new ListNode(1);
    print_res(r2,1);
    delete r2;

    ListNode *r3 = new ListNode(1, new ListNode(2));
    print_res(r3,2);
    delete r3;
}
