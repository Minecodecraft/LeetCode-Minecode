//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/9/21.
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
    int minKnightMoves(int x, int y) {
        queue<Node> Q;
        Q.push(Node());
        vector<vector<bool>> vis (620, vector<bool> (620, false));
        while (!Q.empty()) {
            Node n = Q.front(); Q.pop();
            if (n.x == x && n.y == y) return n.cnt;
            if (vis[n.x+300][n.y+300]) continue;
            vis[n.x+300][n.y+300] = true;
            for (int i = 0; i < 8; ++i) {
                int tox = n.x + dx[i];
                int toy = n.y + dy[i];
                int cnt = n.cnt + 1;
                if (tox < -300 || tox > 300 || toy < -300 || toy > 300)
                    continue;
                Node newNode = Node();
                newNode.x = tox; newNode.y = toy; newNode.cnt = cnt;
                Q.push(newNode);
            }
        }
        return -1;
    }

private:
    vector<int> dx = {1, 2, 2, 1, -1, -2, -2, -1};
    vector<int> dy = {2, 1, -1, -2, -2, -1, 1, 2};
    int AVAI_LEN = 4;

    struct Node {
        int x = 0;
        int y = 0;
        int cnt = 0;
    };
};

int main() {
    Solution sol = Solution();
//    int x = 2, y = 1;
//    int x = 5, y = 5;
    int x = 300, y = 300;
    int res = sol.minKnightMoves(x, y);
    cout << res << endl;
    return 0;
}
