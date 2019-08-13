//
//  main.cpp
//  522. Longest Uncommon Subsequence II
//
//  Created by 边俊林 on 2019/8/13.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/longest-uncommon-subsequence-ii/
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
    int findLUSlength(vector<string>& strs) {
        if (strs.empty()) return -1;
        int res = -1;
        for (int i = 0; i < strs.size(); ++i) {
            int j = 0;
            for (j = 0; j < strs.size(); ++j) {
                if (i == j) continue;
                if (isSubsequence(strs[i], strs[j]))
                    break;
            }
            if (j == strs.size())
                res = max(res, static_cast<int>(strs[i].length()));
        }
        return res;
    }

private:
    bool isSubsequence(const string& a, const string& b) {
        if (b.length() < a.length())
            return false;
        int i = 0;
        for (auto ch : b)
            if (i < a.length() && a[i] == ch)
                ++i;
        return i == a.length();
    }
};

int main() {
    Solution sol = Solution();
//    vector<string> strs = {"aba", "cdc", "eae"};
    vector<string> strs = {"aabbcc", "aabbcc","cb"};
//    vector<string> strs = {"aaa", "aaa", "aa"}; //
//    vector<string> strs = {"aabbcc", "aabbcc", "c", "e"}; // e
//    vector<string> strs = {"aabbcc", "aabbcc","c","e","aabbcd"};
    int res = sol.findLUSlength(strs);
    cout << res << endl;
    return 0;
}
