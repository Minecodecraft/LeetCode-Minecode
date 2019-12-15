//
//  main.cpp
//  D
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
    int shortestPath(vector<vector<int>>& grid, int k) {
        rows = grid.size(), cols = grid[0].size();
        maxk = vector<vector<int>> (rows, vector<int> (cols, -1));
        queue<Node> q;
        bitset<2000> vis = bitset<2000>();
        q.push(Node(0, 0, 0, k, vis));

        while (q.size()) {
            int x = q.front().x, y = q.front().y;
            bitset<2000> vis = q.front().vis;
            int curk = q.front().k, len = q.front().len;
            q.pop();

            if (x == rows-1 && y == cols-1)
                return len;
            vis[x * cols + y] = true;
            if (curk <= maxk[x][y]) continue;
            maxk[x][y] = max(maxk[x][y], curk);

            for (int i = 0; i < 4; ++i) {
                int tx = x + dir[i], ty = y + dir[i+1];
                if (tx>=0 && tx<rows && ty>=0 && ty<cols && !vis[tx * cols + ty]) {
                    int newk = grid[tx][ty] ? curk-1 : curk;
                    if (newk < 0) continue;
                    q.push(Node(tx, ty, len+1, newk, vis));
                }
            }
        }
        return -1;
    }

private:
    unordered_map<int, int> cache;
    int rows, cols;
    vector<int> dir = {1, 0, -1, 0, 1};
    vector<vector<int>> maxk;

    struct Node {
        int x, y;
        int k;
        int len;
        bitset<2000> vis;

        Node(int x, int y, int len, int k, bitset<2000> bt)
        : x(x), y(y), len(len), k(k), vis(bt) { }
    };
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
        {0,0,0},{1,1,0},{0,0,0},{0,1,1},{0,0,0}
    };
    int k = 1;
    int res = sol.shortestPath(mat, k);
    cout << res << endl;
    return 0;
}
