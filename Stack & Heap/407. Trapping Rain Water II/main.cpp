//
//  main.cpp
//  407. Trapping Rain Water II
//
//  Created by 边俊林 on 2019/10/6.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
https://leetcode.com/problems/trapping-rain-water-ii/
\* ------------------------------------------------------ */

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
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int rows = heightMap.size(), cols = heightMap[0].size();
        vector<vector<bool>> vis (rows, vector<bool> (cols, false));
        if (rows <= 1 || cols <= 1) return 0;
        auto cmp = [&heightMap] (Node &a, Node &b) { return a.val > b.val; };
        priority_queue<Node, vector<Node>, decltype(cmp)> pq (cmp);
        for (int i = 0; i < cols; ++i) {
            pq.push(Node(heightMap[0][i], 0, i));
            pq.push(Node(heightMap[rows-1][i], rows-1, i));
        }
        for (int i = 1; i < rows-1; ++i) {
            pq.push(Node(heightMap[i][0], i, 0));
            pq.push(Node(heightMap[i][cols-1], i, cols-1));
        }
        int res = 0, maxval = INT_MIN;
        while (!pq.empty()) {
            Node num = pq.top(); pq.pop();
            if (vis[num.row][num.col]) continue;
            vis[num.row][num.col] = true;
            if (maxval > num.val)
                res += maxval - num.val;
            maxval = max(maxval, num.val);
            for (int i = 0; i < 4; ++i) {
                int toRow = num.row + dirRow[i];
                int toCol = num.col + dirCol[i];
                if (toRow>=0 && toRow<rows && toCol>=0 && toCol<cols && !vis[toRow][toCol])
                    pq.push(Node(heightMap[toRow][toCol], toRow, toCol));
            }
        }
        return res;
    }

private:
    struct Node {
        int val;
        int row, col;
        Node(int val, int row, int col)
        : val(val), row(row), col(col) {}
        Node() {};
    };

    int dirRow[4] = {0, 0, -1, 1};
    int dirCol[4] = {1, -1, 0, 0};
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}
    };
    int res = sol.trapRainWater(mat);
    cout << res << endl;
    return 0;
}
