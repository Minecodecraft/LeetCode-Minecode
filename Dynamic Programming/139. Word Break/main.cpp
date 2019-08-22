//
//  main.cpp
//  139. Word Break
//
//  Created by 边俊林 on 2019/8/22.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/word-break/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
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
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        unordered_set<string> hasa (wordDict.begin(), wordDict.end());
        vector<bool> dp (len+1, false);
        dp[0] = true;
        for (int i = 1; i <= len; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (dp[j-1] && hasa.find(s.substr(j-1, i-j+1)) != hasa.end())
                    dp[i] = true;
            }
        }
        return dp[len];
    }
};

int main() {
    Solution sol = Solution();
//    string s = "leetcode";
//    vector<string> words = {"leet", "code"};
    string s = "applepenapple";
    vector<string> words = {"apple", "pen"};
    auto res = sol.wordBreak(s, words);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
