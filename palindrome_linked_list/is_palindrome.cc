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


static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

// https://www.programcreek.com/2014/07/leetcode-palindrome-linked-list-java/
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;

    ListNode *fast = head;
    ListNode *slow = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode * secondHead = slow->next;
    slow->next = nullptr;

    // reverse the second part
    ListNode *p1 = secondHead;
    ListNode *p2 = p1->next;

    while (p1!=nullptr && p2!=nullptr) {
        ListNode *temp = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = temp;
    }

    secondHead->next = nullptr;

    // compare the two lists
    ListNode *p = (p2 == nullptr)? p1:p2;
    ListNode *q = head;
    while (p!=nullptr) {
        if (p->val != q->val) return false;
        p = p->next;
        q = q->next;
    }


    return true;
}

void print_res(ListNode *head) {
    print_node("h",head);
    bool res = isPalindrome(head);
    cout << "isPalindrome: " << (res?"True":"False") << endl;
}

int main() {
    ListNode *h1 = new ListNode(4, new ListNode(1, new ListNode(4)));
    ListNode *h2 = new ListNode(4, new ListNode(4));
    ListNode *h3 = new ListNode(4);
    ListNode *h4 = new ListNode(4, new ListNode(5));
    ListNode *h5 = nullptr;

    print_res(h1);
    print_res(h2);
    print_res(h3);
    print_res(h4);
    print_res(h5);

    delete h1;
    delete h2;
    delete h3;
    delete h4;
    delete h5;
}
