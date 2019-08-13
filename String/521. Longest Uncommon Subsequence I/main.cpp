//
//  main.cpp
//  521. Longest Uncommon Subsequence I
//
//  Created by 边俊林 on 2019/8/13.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/longest-uncommon-subsequence-i/
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
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max(a.length(), b.length());
    }
};

int main() {
    Solution sol = Solution();
//    string a = "aba";
//    string b = "cdc";
//    string a = "aba";
//    string b = "aa";
//    string a = "aaa";
//    string b = "aaaa";
    string a = "aefawfawfawfaw";
    string b = "aefawfeawfwafwaef";
    int res = sol.findLUSlength(a, b);
    cout << res << endl;
    return 0;
}
