//
//  main.cpp
//  A
//
//  Created by Jaylen Bian on 9/15/20.
//  Copyright © 2020 Jaylen Bian. All rights reserved.
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
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = n == 0 ? 0 : mat[0].size();
        vector<int> hcnt (n, 0), vcnt(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j]) {
                    ++hcnt[i];
                    ++vcnt[j];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] && hcnt[i] == 1 && vcnt[j] == 1)
                    ++res;
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
        {1,0,0}, {0,0,1}, {1,0,0}
    };
    int res = sol.numSpecial(mat);
    cout << res << endl;
    return 0;
}
