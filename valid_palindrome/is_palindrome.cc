#include <string>
#include <iostream>

using namespace std;

bool isAlphaNumeric(char a) {
    return (a >= 'a' && a <= 'z') ||
        (a>= 'A' && a <= 'Z') || 
        (a>= '0' && a <= '9');
}

bool isSame(char a, char b) {
    int d = 'a' - 'A';
    if (a >= 'a' && a <= 'z') {
        a -= d;
    }
    if (b >= 'a' && b <= 'z') {
        b -= d;
    }
    return a == b;
}

bool isPalindrome(string s) {
    int i = 0;
    int j = s.size()-1;
    while (i < j) {
        while (!isAlphaNumeric(s[i])) {
            if (i >= j) goto out;
            i++;
        } 
        while (!isAlphaNumeric(s[j])) {
            j--;
        } 
        // cout << "Comparing " << s[i] << " and " << s[j] << ": " << 
        //     isSame(s[i], s[j]) << endl;
        if (isSame(s[i],s[j])) {
            i++;
            j--;
            continue;
        } else {
            return false;
        }
    }
out:
    return true;
}


void print_res(string s) {
    cout << "isPalindrome(" << s <<"): " << (isPalindrome(s)?"True":"False") << endl;
}

int main() {
    print_res("");
    print_res(",.");
    print_res( "A man, a plan, a canal: Panama");
    print_res("race a car");
}
