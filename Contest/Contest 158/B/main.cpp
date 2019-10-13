//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/10/13.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> hasq (8, vector<bool> (8, false));
        for (int i = 0; i < queens.size(); ++i)
            hasq[queens[i][0]][queens[i][1]] = true;

        int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        queue<Node> Q;
        for (int i = 0; i < 8; ++i) {
            int tox = king[0] + dx[i];
            int toy = king[1] + dy[i];
            if (tox>=0 && tox<8 && toy>=0 && toy<8)
                Q.push({dx[i], dy[i], tox, toy});
        }
        vector<vector<int>> res;
        while (Q.size()) {
            Node cur = Q.front(); Q.pop();
            if (hasq[cur.x][cur.y]) {
                res.push_back({cur.x, cur.y});
                continue;
            }

            int tox = cur.x + cur.dx;
            int toy = cur.y + cur.dy;
            if (tox>=0 && tox<8 && toy>=0 && toy<8)
                Q.push({cur.dx, cur.dy, tox, toy});
        }
        return res;
    }

    struct Node {
        int dx;
        int dy;
        int x;
        int y;
    };
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> q = {
//        {0, 1}, {1, 0}, {4, 0}, {0, 4},
//        {3, 3}, {2, 4}
        {0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}
    };
//    vector<int> k = {0, 0};
    vector<int> k = {3, 3};

    auto res = sol.queensAttacktheKing(q, k);
    cout << res.size() << endl;
    return 0;
}
