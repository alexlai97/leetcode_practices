#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> res;
    for (int i = 1; i <= n; ++i) {
        if (i % 15 == 0) {
            res.push_back("FizzBuzz");
        } else if (i % 3 == 0) {
            res.push_back("Fizz");
        } else if (i % 5 == 0) {
            res.push_back("Buzz");
        } else {
            res.push_back(to_string(i));
        }
    }

    return res;
}

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

void print_res(int n) {
    auto res = fizzBuzz(15);
    print_vector("res:", res);
}

int main() {
    print_res(15);
}
