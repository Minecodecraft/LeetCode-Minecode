//
//  main.cpp
//  44. Wildcard Matching
//
//  Created by 边俊林 on 2019/7/23.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/wildcard-matching/
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
    bool isMatch(string s, string p) {
        return dfs(s, p, 0, 0) == 2;
    }

private:
    int dfs(string& s, string& p, int sidx, int pidx) {
        // 0: s reached end but not match
        // 1: p reached end but not matched or unmatched
        // 2: match
        if (sidx == s.length() && pidx == p.length()) return 2;
        if (sidx == s.length() && p[pidx] != '*') return 0;
        if (pidx == p.length()) return 1;
        if (p[pidx] == '*') {
            if (pidx+1 < p.length() && p[pidx+1] == '*')
                return dfs(s, p, sidx, pidx+1);
            int res;
            for (int i = 0; i <= s.length()-sidx; ++i) {
                res = dfs(s, p, sidx+i, pidx+1);
                if (res == 0 || res == 2) return res;
            }
        }
        if (p[pidx] == '?' || s[sidx] == p[pidx]) {
            return dfs(s, p, sidx+1, pidx+1);
        }
        return 1;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "aa";
//    string p = "*";
//    string s = "cb";
//    string p = "?a";
    string s = "adceb";
    string p = "*a*b";
//    string s = "acdcb";
//    string p = "a*c?b";
//    string s = "aab";
//    string p = "c*a*b";
//    string s = "aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba";
//    string p = "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*";
//    string s = "abbaabbbbababaababababbabbbaaaabbbbaaabbbabaabbbbbabbbbabbabbaaabaaaabbbbbbaaabbabbbbababbbaaabbabbabb";
//    string p = "***b**a*a*b***b*a*b*bbb**baa*bba**b**bb***b*a*aab*a**";
    bool res = sol.isMatch(s, p);
    cout << (res ? "true" : "false") << endl;

    return 0;
}
