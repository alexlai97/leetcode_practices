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

void print_node(string name, ListNode* n) {
    cout << name << ": ";
    while (n) {
        cout << n->val << "->";
        n = n->next;
    }
    cout << "NULL" << endl;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    if (headA == headB) return headA;
    if (headA == headB->next) return headA;
    if (headB == headA->next) return headB;

    int count_A = 0;
    ListNode *cur_headA = headA;
    ListNode *cur_headB = headB;
    while (cur_headA != cur_headB) {
        // next
        cur_headA = cur_headA->next;
        cur_headB = cur_headB->next;
        if (!cur_headA) {
            cur_headA = headB;
            if (count_A >= 2) return nullptr;
            count_A++;
        }
        if (!cur_headB) { 
            cur_headB = headA;
        }
    }

    return cur_headA;
}

void print_res(ListNode *headA, ListNode *headB) {
    ListNode *res = getIntersectionNode(headA, headB);
    print_node("A", headA);
    print_node("B", headB);
    print_node("intersect: ", res);
}

int main() {
    ListNode *c1 = new ListNode(8,new ListNode(4, new ListNode(5)));
    ListNode *a1 = new ListNode(4, new ListNode(1, c1));
    ListNode *b1 = new ListNode(5, new ListNode(0, new ListNode(1, c1)));

    print_res(a1, b1);

    ListNode *a2 = new ListNode(2, new ListNode(6, new ListNode(4)));
    ListNode *b2 = new ListNode(1, new ListNode(5));
    print_res(a2, b2);

    delete a1;
    delete a2;
    delete b2;
}
