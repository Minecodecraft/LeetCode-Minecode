//
//  main.cpp
//  583. Delete Operation for Two Strings
//
//  Created by 边俊林 on 2019/8/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/delete-operation-for-two-strings/
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
    int minDistance(string word1, string word2) {
        int la = word1.length();
        int lb = word2.length();
        // dp[i][j] means the dis of word1[0...i-1], word2[0...j-1]
        vector<vector<int>> dp (la+1, vector<int> (lb+1, 0));
        for (int i = 1; i <= la; ++i) {
            for (int j = 1; j <= lb; ++j) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]);

                if (word1[i-1] == word2[j-1])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
        return la + lb - dp[la][lb] * 2;
    }
};

int main() {
    Solution sol = Solution();
    string s1 = "sea";
    string s2 = "eat";
    int res = sol.minDistance(s1, s2);
    cout << res << endl;
    return 0;
}
