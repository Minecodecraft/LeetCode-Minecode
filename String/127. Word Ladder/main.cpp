//
//  main.cpp
//  127. Word Ladder
//
//  Created by 边俊林 on 2019/8/4.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/word-ladder/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution: Two Pointer
//
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wl (wordList.begin(), wordList.end());
        unordered_set<string> q1, q2;
        if (wl.find(endWord) == wl.end())
            return 0;
        unordered_set<string>* pq1,* pq2;
        q1.insert(beginWord);
        q2.insert(endWord);
        int level = 1;
        while (!q1.empty() && !q2.empty()) {
            pq1 = q1.size() < q2.size() ? &q1 : & q2;
            pq2 = q1.size() < q2.size() ? &q2 : & q1;

            ++level;
            unordered_set<string> tmp;
            for (auto it = pq1->begin(); it != pq1->end(); ++it) {
                string word = *it;
                for (int i = 0; i < word.length(); ++i) {
                    char ch = word[i];
                    for (int j = 0; j < 26; ++j) {
                        word[i] = 'a' + j;
                        if (pq2->find(word) != pq2->end())
                            return level;
                        if (wl.find(word) != wl.end()) {
                            wl.erase(word);
                            tmp.insert(word);
                        }
                    }
                    word[i] = ch;
                }
            }
            pq1->swap(tmp);
        }
        return 0;
    }
};

int main() {
    Solution sol = Solution();
    string beg = "hit";
    string end = "cog";
//    vector<string> wl = { "hot","dot","dog","lot","log","cog" };
    vector<string> wl = {"hot","dot","dog","lot","log"};
    auto res = sol.ladderLength(beg, end, wl);
    cout << res << endl;
    return 0;
}
