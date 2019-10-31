//
//  main.cpp
//  329. Longest Increasing Path in a Matrix
//
//  Created by 边俊林 on 2019/10/31.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
// Solution 1: BFS, Only beats 5%
/*
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
        vector<vector<int>> maxx (rows, vector<int> (cols, 0));
        int dir[5] = {0, 1, 0, -1, 0};
        
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                q.push(make_pair(1, i*cols+j));
        
        int res = 0;
        while (q.size()) {
            auto pir = q.front(); q.pop();
            int cnt = pir.first, r = pir.second / cols, c = pir.second % cols;
            if (maxx[r][c] >= cnt) continue;
            maxx[r][c] = cnt;
            res = max(res, maxx[r][c]);
            
            for (int i = 0; i < 4; ++i) {
                int tr = r + dir[i];
                int tc = c + dir[i+1];
                if (tr>=0 && tr<rows && tc>=0 && tc<cols &&
                    matrix[tr][tc] > matrix[r][c]) {
                    q.push(make_pair(cnt+1, tr*cols+tc));
                }
            }
        }
        return res;
    }
};
 */

// Solution 2: DFS
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0;
        vector<vector<int>> cache (matrix.size(), vector<int> (matrix[0].size(), 0));
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                res = max(res, dfs(matrix, i, j, INT_MIN, cache));
            }
        }
        return res;
    }
    
private:
    int dfs(vector<vector<int>>& mat, int x, int y, int val, vector<vector<int>>& cache) {
        if (x<0 || x>=mat.size() || y<0 || y>=mat[0].size())
            return 0;
        if (mat[x][y] > val) {
            if (cache[x][y] != 0)
                return cache[x][y];
            int a = dfs(mat, x, y+1, mat[x][y], cache) + 1;
            int b = dfs(mat, x, y-1, mat[x][y], cache) + 1;
            int c = dfs(mat, x+1, y, mat[x][y], cache) + 1;
            int d = dfs(mat, x-1, y, mat[x][y], cache) + 1;
            return cache[x][y] = max(a, max(b, max(c, d)));
        }
        return 0;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {9,9,4}, {6,6,8}, {2,1,1}
//        {3,4,5}, {3,2,6}, {2,2,1}
        {1, 2, 3}
    };
    int res = sol.longestIncreasingPath(mat);
    cout << res << endl;
    return 0;
}
