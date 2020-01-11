//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2020/1/11.
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
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        n = mat.size(), m = mat[0].size();
        sum = vector<vector<int>> (n, vector<int> (m+1, 0));
        vector<vector<int>> res (n, vector<int> (m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sum[i][j+1] = sum[i][j] + mat[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = getSum(i-k, i+k, j-k, j+k);
            }
        }

        return res;
    }

private:
    vector<vector<int>> sum;
    int n, m;

    int getSum(int tr, int br, int lc, int rc) {
        tr = max(tr, 0);
        br = min(br, n-1);
        lc = max(lc, 0);
        rc = min(rc, m-1);
        int res = 0;
        for (int r = tr; r <= br; ++r) {
            res += sum[r][rc+1] - sum[r][lc];
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();

    vector<vector<int>> mat = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
    };
    auto res = sol.matrixBlockSum(mat, 1);
    cout << res.size() << endl;

    return 0;
}
