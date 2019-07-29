//
//  main.cpp
//  87. Scramble String
//
//  Created by 边俊林 on 2019/7/29.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/scramble-string/
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

/// Solution:
//
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        fill(cnt.begin(), cnt.end(), 0);
        int len = s1.length();
        for (int i = 0; i < len; ++i) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i)
            if (cnt[i] != 0) return false;

        for (int i = 1; i <= len-1; ++i) {
            if ((
                isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))
            ) || (
                isScramble(s1.substr(0, i), s2.substr(len-i)) &&
                isScramble(s1.substr(i), s2.substr(0, len-i))
            ))
                return true;
        }
        return false;
    }

private:
    vector<int> cnt = vector<int>(26, 0);
};

int main() {
    Solution sol = Solution();
    string s1 = "great";
    string s2 = "rgeat";
//    string s1 = "abcde";
//    string s2 = "caebd";
//    string s1 = "great";
//    string s2 = "rgtae";
//    string s1 = "great";
//    string s2 = "rgtea";
//    string s1 = "abc";
//    string s2 = "bca";
    bool res = sol.isScramble(s1, s2);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
