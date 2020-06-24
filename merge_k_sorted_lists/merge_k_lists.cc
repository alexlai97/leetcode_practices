#include <iostream>
#include <vector>
#include <queue>

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


struct compare { 
    bool operator()(ListNode *l1, ListNode *l2) 
    { 
        return l1->val > l2->val;
    } 
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode* root = new ListNode(); 
    ListNode* cur = root;
    priority_queue<ListNode*,vector<ListNode*>, compare> pq;
    for (auto l: lists) {
        if (l) pq.push(l);
    }

    while (!pq.empty()) {
        ListNode* top = pq.top();
        pq.pop();
        if (top->next) pq.push(top->next);

        ListNode* new_node = new ListNode(top->val);
        cur->next = new_node;
        cur = cur->next;
    }

    ListNode*res = root->next;
    root->next = nullptr;
    delete root;
    return res;
}


void print_res(vector<ListNode*>& lists) {
    ListNode * res = mergeKLists(lists);
    for (int i = 0; i < lists.size(); ++i) {
        print_node(to_string(1), lists[i]);
    }
    print_node("merged", res);
    delete res;
}

int main() {
    ListNode *l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode *l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *l3 = new ListNode(2, new ListNode(6));
    vector<ListNode*>lists1 = {l1,l2,l3};
    print_res(lists1);

    delete l1; delete l2; delete l3;
}
