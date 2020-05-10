#include <iostream>
using namespace std;


int trailingZeroes(int n) {
    int sum = 0;
    for (unsigned long i = 5; i <= n; i*= 5) {
        sum += n/i;
    }
    return sum;
}

int main() {
    int n = 1808548329;
    cout << "trailingZeroes(" << n << ")" <<  " = " << trailingZeroes(n) << endl;;

}
