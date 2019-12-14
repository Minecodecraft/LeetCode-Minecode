//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2019/12/14.
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
    int minFallingPathSum(vector<vector<int>>& arr) {
        int res = INT_MAX;
        for (int i = 0; i < arr.size(); ++i) {
            res = min(res, dfs(arr, 0, i));
        }
        return res;
    }

private:
    unordered_map<int, int> cache;

    int dfs(vector<vector<int>>& mat, int r, int c) {
        int key = r + c * 345;
        if (cache.count(key))
            return cache[key];

        if (r == mat.size()-1)
            return cache[key] = mat[r][c];

        int tmp = INT_MAX;
        for (int i = 0; i < mat.size(); ++i) {
            if (i == c) continue;
            tmp = min(tmp, dfs(mat, r+1, i));
        }
        return cache[key] = tmp + mat[r][c];
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
        {1, 2, 3}, {4, 5, 6}, {7, 8, 9}
//        {2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2}
    };
    int res = sol.minFallingPathSum(mat);
    cout << res << endl;

    return 0;
}
