#include <iostream>
#include <vector>
#include <string>
using namespace std;

// FIXME: not finished

template <typename T>
void print_vector(string name, vector<T> &v) {
    cout << name << ": [";
    for (auto i: v) cout << i << ", ";
    cout << "]" << endl;
}

int leastInterval(vector<char>& tasks, int n) {
        
    return 0;
}

int main() {
    vector<char> tasks = { 'A','A','A','B','B','B' };
    int n = 2;
    int res = leastInterval(tasks, n);
    print_vector("tasks", tasks);
    cout << "leastInterval: " << res << endl;
}
