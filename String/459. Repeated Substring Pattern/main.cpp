//
//  main.cpp
//  459. Repeated Substring Pattern
//
//  Created by 边俊林 on 2019/8/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/repeated-substring-pattern/
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
class Solution {public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 2; i <= n; ++i) {
            if (n % i != 0) continue;
            int itemlen = n / i;
            int j = 1;
            string oris = s.substr(0, itemlen);
            for (; j < n/itemlen; ++j) {
                string tmp = s.substr(j * itemlen, itemlen);
                if (oris != tmp) break;
            }
            if (j == n/itemlen)
                return true;
        }
        return false;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "abab";
//    string s = "aba";
    string s = "abcabcabcabc";
    auto res = sol.repeatedSubstringPattern(s);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
