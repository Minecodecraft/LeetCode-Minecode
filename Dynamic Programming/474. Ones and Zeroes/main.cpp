//
//  main.cpp
//  474. Ones and Zeroes
//
//  Created by 边俊林 on 2019/9/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/ones-and-zeroes/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
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
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
        for (int i = 0; i < strs.size(); ++i) {
            int zerocnt = 0, onecnt = 0;
            for (auto &ch: strs[i]) {
                if (ch == '1') onecnt++;
                else zerocnt++;
            }
            for (int mi = m; mi >= zerocnt; --mi) {
                for (int ni = n; ni >= onecnt; --ni) {
                    dp[mi][ni] = max(dp[mi][ni], dp[mi-zerocnt][ni-onecnt] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol = Solution();
    vector<string> strs = {
//        "10","0001","111001","1","0"
        "10", "0", "1"
    };
    int m = 1;
    int n = 1;
//    int m = 5;
//    int n = 3;
    int res = sol.findMaxForm(strs, m, n);
    cout << res << endl;
    return 0;
}
