//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2020/1/12.
//  Copyright © 2020 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    int minimumDistance(string word) {
        unordered_map<char, pair<int, int>> pos;
        for (int i = 0; i < 26; ++i) {
            char ch = i + 'A';
            int r = i / 6, c = i % 6;
            pos[ch] = {r, c};
        }
        vector<vector<int>> dst (26, vector<int> (26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = i; j < 26; ++j) {
                if (i == j) continue;
                auto& pa = pos[i+'A'];
                auto& pb = pos[j+'A'];
                dst[i][j] = dst[j][i] = abs(pa.first-pb.first) + abs(pa.second-pb.second);
            }
        }

        int len = word.length();
        int dp[len+1][26][26];
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                dp[0][i][j] = 0;

        for (int i = 1; i <= len; ++i) {
            int ch = word[i-1] - 'A';
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < 26; ++k)
                    dp[i][j][k] = 0x3f3f3f3f;
            for (int j = 0; j < 26; ++j)
                for (int k = 0; k < 26; ++k) {
                    dp[i][ch][k] = min(dp[i][ch][k],
                                       dp[i-1][j][k] + dst[ch][j]);
                    dp[i][j][ch] = min(dp[i][j][ch],
                                        dp[i-1][j][k] + dst[ch][k]);
                }
        }

        int res = INT_MAX;
        for (int j = 0; j < 26; ++j)
            for (int k = 0; k < 26; ++k)
                res = min(res, dp[len][j][k]);
        return res;
    }
};

int main() {

    Solution sol = Solution();
//    string w = "CAKE";
    string w = "HAPPY";
    int res = sol.minimumDistance(w);
    cout << res << endl;

    return 0;
}
