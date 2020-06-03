#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// FIXME: not finished

template <typename T>
void print_vector(string name, vector<T> &v) {
    cout << name << ": [";
    for (auto i: v) cout << i << ", ";
    cout << "]" << endl;
}

// from leetcode "solution" section
// brilliant yet simple solution
int leastInterval(vector<char>& tasks, int n) {
    int len = tasks.size();
    int* table = new int[26];
    fill(table,table+26,0);

    for (auto c: tasks)
        table[c-'A']++;

    sort(table,table+26);

    int limit = table[25] - 1;
    int idle_slots = limit * n;

    for (int i = 24; i >=0 && table[i] > 0; --i) {
        idle_slots -= min(limit,table[i]);
    }

    delete[] table;

    int res = (idle_slots > 0)? idle_slots+len : len;
    return res;
}

int main() {
    vector<char> tasks = { 'A','A','A','B','B', 'B'};
    int n = 2;
    print_vector("tasks", tasks);
    int res = leastInterval(tasks, n);
    cout << "leastInterval: " << res << endl;
}
