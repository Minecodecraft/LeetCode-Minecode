//
//  main.cpp
//  864. Shortest Path to Get All Keys
//
//  Created by 边俊林 on 2019/10/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/shortest-path-to-get-all-keys/
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
    int shortestPathAllKeys(vector<string>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<vector<bool>>> vis (rows, vector<vector<bool>> (cols, vector<bool> (64, false)));

        int K = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '@')
                    vis[i][j][0] = true, q.emplace(i*cols+j, 0);
                if (grid[i][j] >= 'A' && grid[i][j] <= 'F') ++K;
            }
        }

        int stepCnt = 0;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front().first / cols, y = q.front().first % cols;
                int mask = q.front().second;
                q.pop();

                if (mask == ((1 << K)-1))
                    return stepCnt;

                for (int i = 0; i < 4; ++i) {
                    int tox = x + dx[i];
                    int toy = y + dy[i];
                    int tomask = mask;
                    if (tox<0 || tox>=rows || toy<0 || toy >= cols || grid[tox][toy] == '#') continue;
                    char ch = grid[tox][toy];
                    if (ch >= 'a' && ch <= 'f') {
                        tomask |= (1 << (ch-'a'));
                    } else if (ch >= 'A' && ch <= 'F') {
                        if (!(tomask & (1 << (ch-'A')))) continue;
                    }
                    if (!vis[tox][toy][tomask]) {
                        vis[tox][toy][tomask] = true;
                        q.emplace(tox*cols+toy, tomask);
                    }
                }
            }
            ++stepCnt;
        }
        return -1;
    }

private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
};

int main() {
    Solution sol = Solution();
    vector<string> grid = {
//        "@.a.#","###.#","b.A.B"
//        "@..aA","..B#.","....b"
//        ".@aA"
//        "@...a",".###A","b.BCc"
        "b","A","a","@","B"
    };
    int res = sol.shortestPathAllKeys(grid);
    cout << res << endl;
    return 0;
}
