//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2020/2/22.
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
    int numberOfSubstrings(string s) {
        int len = s.length();
        vector<vector<int>> p = vector<vector<int>> (3);
        vector<char> chs = {'a', 'b', 'c'};
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'a') p[0].push_back(i);
            if (s[i] == 'b') p[1].push_back(i);
            if (s[i] == 'c') p[2].push_back(i);
        }
        if (!p[0].size() || !p[1].size() || !p[2].size()) return 0;

        // res
        int res = 0;
        for (int i = 0; i < len; ++i) {
            int j = i;
            for (int idx = 0; idx < 3; ++idx) {
                auto it = lower_bound(p[idx].begin(), p[idx].end(), i);
                if (it == p[idx].end()) {
                    j = len; break;
                } else {
                    j = max(j, *it);
                }
            }
            res += len - j;
        }

        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "abcabc";
    int res = sol.numberOfSubstrings(s);
    cout << res << endl;
    return 0;
}
