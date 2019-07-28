//
//  main.cpp
//  72. Edit Distance
//
//  Created by 边俊林 on 2019/7/28.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/edit-distance/
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
/* Solution 1:  有可优化点，见Solution2
class Solution {
public:
    int minDistance(string word1, string word2) {
        int la = word1.length(), lb = word2.length();
        // dp[i][j] means the step convert word1[0...i-1) to word2[0...j-1)
        vector<vector<int>> dp (la+1, vector<int> (lb+1, 0));
        for (int i = 1; i <= la; ++i)
            dp[i][0] = i;
        for (int i = 1; i <= lb; ++i)
            dp[0][i] = i;

        for (int i = 1; i <= la; ++i) {
            for (int j = 1; j <= lb; ++j) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }

        return dp[la][lb];
    }
};
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int la = word1.length(), lb = word2.length();
        // dp[i][j] means the step convert word1[0...i-1) to word2[0...j-1)
        vector<int> pre (lb+1, 0);
        vector<int> cur (lb+1, 0);
        for (int i = 1; i <= lb; ++i)
            pre[i] = i;

        for (int i = 1; i <= la; ++i) {
            cur[0] = i;
            for (int j = 1; j <= lb; ++j) {
                if (word1[i-1] == word2[j-1])
                    cur[j] = pre[j-1];
                else
                    cur[j] = min(pre[j-1], min(cur[j-1], pre[j])) + 1;
            }
            fill(pre.begin(), pre.end(), 0);
            swap(pre, cur);
        }
        return pre[lb];
    }
};

int main() {
    Solution sol = Solution();
    string word1 = "horse";
    string word2 = "ros";
//    string word1 = "intention";
//    string word2 = "execution";
//    string word1 = "horse";
//    string word2 = "";
//    string word1 = "";
//    string word2 = "ros";
    int res = sol.minDistance(word1, word2);
    cout << res << endl;
    return 0;
}
