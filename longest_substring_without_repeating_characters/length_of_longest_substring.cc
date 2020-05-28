#include <iostream>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// very slow
int lengthOfLongestSubstring1(string s) {
    if (s.empty()) return 0;
    int max = 0;
    for (int i = 0; i < s.size(); ++i) {
        set<char> st;
        
        for (int j = i; j < s.size(); ++j) {
            if (st.find(s[j]) == st.end()) {
                st.insert(s[j]);
            } else {
                break;
            }
        }

        int cur_size = st.size();
        if (cur_size > max) max = cur_size;
    }

    return max;
}

// sliding window
int lengthOfLongestSubstring2(string s) {
    int len = s.size();
    int ans = 0;
    
    unordered_set<int> st;

    int i = 0, j = 0;
    while (i < len && j < len) {
        // cout << "i: "  << i << ", j: " << j << endl;
        if (st.find(s[j]) == st.end()) {
            // not found
            st.insert(s[j++]);
            ans = max(ans,j-i);
        } else {
            st.erase(s[i++]);
        }
    }

    return ans;
}

// sliding window (storing char indexes)
int lengthOfLongestSubstring3(string s) {
    int len = s.size(), ans = 0;
    
    unordered_map<char,int> mp;

    for (int i = 0, j = 0; j < len; ++j) {
        if (mp.find(s[j]) != mp.end()) {
            i = max(mp[s[j]], i); // FIXME: why ?
            // i = mp[s[j]];
        }
        ans = max(ans, j-i+1);
        mp[s[j]]=j+1; // next jumping index
    }

    return ans;
}


void print_res(string s) {
    cout << "lengthOfLongestSubstring3(" << s << ") = " << lengthOfLongestSubstring3(s) << endl;
}

int main() {
    print_res("abcabcbb");
    print_res("bbbbb");
    print_res("pwwkew");
}
