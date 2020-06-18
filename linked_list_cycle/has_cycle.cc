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


bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }
    return false;
}

void print_res(ListNode *head) {
    cout << "hasCycle: " << (hasCycle(head)?"True":"False") << endl;
}

int main() {
    ListNode *a0 = new ListNode(-4);
    ListNode *a1 = new ListNode(2, new ListNode (0, a0));
    a0->next = a1;
    ListNode *a2 = new ListNode(3, a1);
    print_res(a2);

    ListNode *b1 = new ListNode(1, new ListNode(2));
    print_res(b1);

}
