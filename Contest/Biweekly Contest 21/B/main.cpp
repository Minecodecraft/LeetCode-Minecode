//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2020/3/7.
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
    int findTheLongestSubstring(string s) {
        int len = s.length();
        vector<char> chs = {'a', 'e', 'i', 'o', 'u'};
        vector<vector<int>> sum (5, vector<int> (len+1, 0));
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < 5; ++j) {
                sum[j][i+1] = sum[j][i];
                if (s[i] == chs[j])
                    sum[j][i+1]++;
            }
        }
        for (int i = len; i >= 0; --i) {
            for (int j = 0; j <= len - i; ++j) {
                bool flag = true;
                for (int k = 0; k < 5; ++k) {
                    if ((sum[k][j+i] - sum[k][j]) & 1) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    return i;
            }
        }
        return 0;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "eleetminicoworoep";
    string s = "bcbcbc";
    int res = sol.findTheLongestSubstring(s);
    cout << res << endl;
    return 0;
}
