//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/12/15.
//  Copyright © 2019 边俊林. All rights reserved.
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
    int maxSideLength(vector<vector<int>>& mat, int thr) {
        int rows = mat.size(), cols= mat[0].size();
        vector<vector<int>> sum (rows+1, vector<int> (cols+1, 0));
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                sum[r+1][c+1] = sum[r][c+1] + sum[r+1][c] - sum[r][c] + mat[r][c];
            }
        }

        int maxlen = min(rows, cols);
        for (int len = maxlen; len >= 0; --len) {
            for (int r = rows-1; r >= 0; --r) {
                if (r + 1 < len) break;
                for (int c = cols-1; c >= 0; --c) {
                    if (c + 1 < len) break;
                    int ltr = r - len, ltc = c-len;
                    int cursum = sum[r+1][c+1] - sum[ltr+1][c+1] - sum[r+1][ltc+1] + sum[ltr+1][ltc+1];
                    if (cursum <= thr) return len;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
        {1,1,3,2,4,3,2},{1,1,3,2,4,3,2},{1,1,3,2,4,3,2}
    };
    int thr = 4;
    int res = sol.maxSideLength(mat, thr);
    cout << res << endl;
    return 0;
}
