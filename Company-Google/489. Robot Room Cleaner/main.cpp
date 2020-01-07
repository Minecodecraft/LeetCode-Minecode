//
//  main.cpp
//  489. Robot Room Cleaner
//
//  Created by 边俊林 on 2019/12/29.
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
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }

private:
    set<long long> vis;
    vector<int> dirx = {1, 0, -1, 0};
    vector<int> diry = {0, -1, 0, 1};

    void dfs(Robot& rbt, long long x, long long y, int curd) {
        rbt.clean();
        vis.insert(getKey(x, y));

        for (int i = 0; i < 4; ++i) {
            int dx = x + dirx[curd], dy = y + diry[curd];
            if (!vis.count(getKey(dx, dy)) && rbt.move()) {
                dfs(rbt, dx, dy, curd);
            }
            rbt.turnRight();
            curd++;
            curd %= 4;
        }
        rbt.turnLeft();
        rbt.turnLeft();
        rbt.move();
        rbt.turnLeft();
        rbt.turnLeft();
    }

    long long getKey(long long x, long long y) {
        return x * (1 << 16 - 1) + y;
    }
};

int main() {

    return 0;
}
