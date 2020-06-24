#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

template <typename T>
void print_vector(string name, vector<T> &v) {
    if (!name.empty()) 
        cout << name << ":";
    cout << " [";
    for (auto i: v) cout << i << ", ";
    cout << "]," << endl;
}

auto speed_up = [](){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  return 0;
} ();

// https://leetcode.com/articles/word-ladder/
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int L = beginWord.size();
    if (L != endWord.size()) return 0;

    // construct allComboDict (key: generic_word, val: vector of concrete words)
    unordered_map<string, vector<string>> allComboDict;
    for (auto word: wordList) {
        if (word.size() != L) continue;
        for (int i = 0; i < L; ++i) {
            string generic_word = word;
            generic_word[i] = '*';
            
            if (allComboDict.find(generic_word) == allComboDict.end()) {
                allComboDict[generic_word] = vector<string>{word};
            } else {
                vector<string> &concrete_list = allComboDict[generic_word];
                concrete_list.push_back(word);
            }
        }
    }

    // queue of pair of word and level
    queue<pair<string,int>> Q;

    Q.push(make_pair(beginWord,1));

    // visited word
    unordered_set<string> visited_word_list;
    visited_word_list.insert(beginWord);

    // starting BFS
    while (!Q.empty()) {
        string front_word = Q.front().first;
        int level = Q.front().second;
        Q.pop();

        // for each generic word
        for (int i = 0; i < L; ++i) {
            string generic_word = front_word;
            generic_word[i] = '*';

            if (allComboDict.find(generic_word) == allComboDict.end()) {
                // do nothing
                continue;
            } else {
                // loop through neighours
                vector<string> &concrete_list = allComboDict[generic_word];
                for (auto neighbour: concrete_list) {
                    if (neighbour == endWord) {
                        return level + 1;
                    } else if (visited_word_list.find(neighbour) != visited_word_list.end()) {
                        continue;
                    } else {
                        visited_word_list.insert(neighbour);
                        Q.push(make_pair(neighbour,level+1));
                    }
                }
            }
        }
    }

    return 0;
}

void print_res(string beginWord, string endWord, vector<string>& wordList) {
    cout << "beginWord: " << beginWord << endl;
    cout << "endWord: " << endWord << endl;
    print_vector("wordList", wordList);
    cout << "ladderLength: " <<  ladderLength(beginWord, endWord, wordList) << endl;
}

int main() {
    vector<string> wordList1 = { "hot","dot","dog","lot","log","cog" };

    print_res("hit", "cog", wordList1);
}
