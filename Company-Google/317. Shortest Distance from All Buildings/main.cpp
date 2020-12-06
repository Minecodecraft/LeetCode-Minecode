//
//  main.cpp
//  317. Shortest Distance from All Buildings
//
//  Created by Jaylen Bian on 12/6/20.
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
// Solution 1: Simple BFS, 228ms
/**
class Solution {
    struct Node {
        int x;
        int y;
        int dis;
    };

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = n == 0 ? 0 : grid[0].size(), cnt = 0;
        vector<pair<int, int>> blds;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1)
                    blds.emplace_back(r, c);
            }
        }
        vector<vector<int>> matched = vector<vector<int>> (n, vector<int> (m, 0));
        vector<vector<int>> totdis = vector<vector<int>> (n, vector<int> (m, 0));

        // bfs
        for (int i = 0; i < blds.size(); ++i) {
            vector<vector<bool>> vis = vector<vector<bool>> (n, vector<bool> (m, false));
            queue<Node> q;
            q.push({blds[i].first, blds[i].second, 0});
            while (q.size()) {
                Node& pos = q.front();
                int x = pos.x, y = pos.y, dis = pos.dis;
                q.pop();
                if (vis[x][y])
                    continue;;
                vis[x][y] = true;
                matched[x][y]++;
                totdis[x][y] += dis;

                for (int i = 0; i < 4; ++i) {
                    int tx = x + dx[i], ty = y + dy[i];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m && !vis[tx][ty] && grid[tx][ty] == 0)
                        q.push({tx, ty, dis+1});
                }
            }
        }

        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 0 && matched[i][j] == blds.size()) {
                    res = min(res, totdis[i][j]);
                }
            }
        }
        return res==INT_MAX ? -1 : res;
    }
};
 */

// Solution 2: Reuse the grid to optimize `vis` array, 32ms
class Solution {
    int dir[5] = {0, 1, 0, -1, 0};
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = n == 0 ? 0 : grid[0].size();
        int mindis = -1, emptyval = 0; // empty val means the val that marks an empty land which you can pass by.
        auto tot = grid;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    mindis = -1;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    auto dis = grid;
                    while (q.size()) {
                        int x = q.front().first, y = q.front().second;
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int tx = x + dir[k], ty = y + dir[k+1];
                            if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == emptyval) {
                                q.emplace(tx, ty);
                                grid[tx][ty]--;
                                dis[tx][ty] = dis[x][y] + 1;
                                tot[tx][ty] += dis[tx][ty] - 1;
                                if (mindis == -1 || mindis > tot[tx][ty])
                                    mindis = tot[tx][ty];
                            }
                        }
                    }
                    --emptyval;
                }
            }
        }
        return mindis;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> g = {
        {1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}
//        {1,1,1,1,1,0},{0,0,0,0,0,1},{0,1,1,0,0,1},{1,0,0,1,0,1},{1,0,1,0,0,1},{1,0,0,0,0,1},{0,1,1,1,1,0}
    };
    int res = sol.shortestDistance(g);
    cout << res << endl;
    return 0;
}
