//
//  main.cpp
//  316. Remove Duplicate Letters
//
//  Created by 边俊林 on 2019/10/3.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/remove-duplicate-letters/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt (26, 0);
        for (char &ch: s) cnt[ch-'a']++;
        int idx = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] < s[idx]) idx = i;
            if (--cnt[s[i] - 'a'] == 0) break;
        }
        if (s.empty())
            return "";
        else {
            string buffer = s.substr(idx+1);
            buffer.erase(remove(buffer.begin(), buffer.end(), s[idx]), buffer.end());
            return s[idx] + removeDuplicateLetters(buffer);
        }
    }
};

int main() {
    Solution sol = Solution();
    string s = "bcabc";
//    string s = "cbacdcbc";
    string res = sol.removeDuplicateLetters(s);
    cout << res << endl;
    return 0;
}
