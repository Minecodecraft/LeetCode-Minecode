//
//  main.cpp
//  214. Shortest Palindrome
//
//  Created by 边俊林 on 2019/8/5.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/shortest-palindrome/
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
    string shortestPalindrome(string s) {
        string rs = s;
        reverse(rs.begin(), rs.end());
        string sp = s + "#" + rs;
        vector<int> kmp (sp.length(), 0);
        // Construct KMP arr
        int idx = 0;
        for (int i = 1; i < sp.length(); ++i) {
            if (sp[i] == sp[idx]) {
                kmp[i] = kmp[i-1] + 1;
                idx++;
            } else {
                idx = kmp[i-1];
                while (idx > 0 && sp[i] != sp[idx])
                    idx = kmp[idx-1];
                if (sp[i] == sp[idx])
                    ++idx;
                kmp[i] = idx;
            }
        }
        int len = kmp[sp.length()-1];
        return rs.substr(0, s.length()-len) + s;
    }
};

int main() {
    Solution sol = Solution();
    string s = "aacecaaa";
//    string s = "abcd";
    auto res = sol.shortestPalindrome(s);
    cout << res << endl;
    return 0;
}
