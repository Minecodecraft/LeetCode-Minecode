//
//  main.cpp
//  279. Perfect Squares
//
//  Created by 边俊林 on 2019/8/27.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
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
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; ;++i) {
            int tmp = i * i;
            if (tmp > n) break;
            squares.push_back(tmp);
        }
        vector<int> dp (n+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < squares.size(); ++j) {
                if (squares[j] > i) break;
                dp[i] = min(dp[i], dp[i-squares[j]] + 1);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol = Solution();
//    int n = 12;
//    int n = 13;
//    int n = 1;
    int n = 4635;
    int res = sol.numSquares(n);
    cout << res << endl;
    return 0;
}
