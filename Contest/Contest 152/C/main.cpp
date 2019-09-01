//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/9/1.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

// https://leetcode.com/contest/weekly-contest-152/problems/can-make-palindrome-from-substring/

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

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int len = s.length(), sz = queries.size();
        vector<vector<int>> wordcnt (26, vector<int> (len+1, 0));

        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= len; ++j) {
                wordcnt[i][j] = wordcnt[i][j-1];
                if (s[j-1] == ('a'+i)) {
                    wordcnt[i][j]++;
                }
            }
        }

        vector<bool> res;
        for (int i = 0; i < sz; ++i) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2];
            int oddcnt = 0;
            for (int j = 0; j < 26; ++j) {
                if ((wordcnt[j][r+1] - wordcnt[j][l]) & 1)
                    ++oddcnt;
            }
            if (oddcnt > 2*k+1)
                res.push_back(false);
            else
                res.push_back(true);
        }

        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol = Solution();
    string s = "abcda";
    vector<vector<int>> q = {
        {3, 3,0}, {1,2,0}, {0,3,1}, {0,3,2}, {0,4,1}
    };
    auto res = sol.canMakePaliQueries(s, q);
    return 0;
}
