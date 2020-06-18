#include <iostream>
#include <math.h>       /* log10 */
#include <climits>       /* log10 */
using namespace std;

int reverse2(int x) {
    int rev = 0;

    while (x != 0) {
        int pop = x % 10;
        x /= 10;

        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;

        rev = rev * 10 + pop;
    }
    return rev;
}

int reverse3(int x) {
    string s=to_string(x);
    for(int i=0;i<s.length()/2;i++)swap(s[i],s[s.length()-1-i]);
    long long y=stoll(s);
    if(y>INT_MAX)return 0;
    if(x<0)y*=-1;
    return y;
}

int reverse(int x) {
    if (x == 0) return 0;
    int n = log10(abs(x));
    int i = pow(10,n);
    
    int q=1,r;
    int res = 0;
    while (q != 0) {
        q = x / 10;
        r = x % 10;
        x/=10;

        res+=(double)i*r;
        i/=10;
    }
    return res;
}


void print_res(int x) {
    cout << "reverse(" << x << "): " << reverse3(x) << endl;
}

int main() {
    print_res(-112);
    print_res(-120);
    print_res(120);
    print_res(1);
    print_res(0);
    print_res(3012938);
    print_res(1534236469);
}
