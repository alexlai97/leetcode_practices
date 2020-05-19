#include <iostream>

using namespace std;

int myPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int titleToNumber(string s) {
    int sum = 0;
    for (int i = s.size()-1; i >= 0; --i) {
        sum+= (s[i] - 'A' + 1) * myPow(26, (s.size() - i-1));
    }
    return sum;
}

int titleToNumber2(string s) {
    long sum = 0;
    for (auto c: s) {
        sum = sum * 26 + c - 'A' + 1;
    }
    return (int) sum;
}

void print_res(string s) {
    cout << "titleToNumber(" << s << ") = " << titleToNumber2(s) << endl;
}
int main() {
    print_res("A");
    print_res("AB");
    print_res("ABC");
    print_res("ZY");
}
