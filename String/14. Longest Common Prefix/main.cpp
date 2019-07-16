//
//  main.cpp
//  14. Longest Common Prefix
//
//  Created by 边俊林 on 2019/7/16.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/longest-common-prefix/
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
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int p = 0;
        while (true) {
            char* ch = NULL;
            for (int i = 0; i < strs.size(); ++i) {
                if (strs[i].length() <= p)
                    return strs[i].substr(0, p);
                if (ch == NULL) ch = &strs[i][p];
                if (*ch != strs[i][p])
                    return strs[i].substr(0, p);
            }
            ++p;
        }
    }
};

int main() {
    Solution sol = Solution();
//    vector<string> strs = {"flower","flow","flight"};
//    vector<string> strs = {"dog","racecar","car"};
    vector<string> strs = {};
    auto res = sol.longestCommonPrefix(strs);
    cout << res << endl;
    return 0;
}
