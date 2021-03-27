//
//  main.cpp
//  1041. Robot Bounded In Circle
//
//  Created by Jaylen Bian on 3/28/21.
//  Copyright © 2021 边俊林. All rights reserved.
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
    bool isRobotBounded(string ins) {
        int x = 0, y = 0, dir = 0, len = ins.length();
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};

        for (int i = 0; i < len * 4; ++i) {
            int idx = i % len;
            if (ins[idx] == 'G') {
                x += dx[dir];
                y += dy[dir];
            } else {
                dir += ins[idx] == 'L' ? 1 : -1;
                dir = (dir+4) % 4;
            }
        }
        return x == 0 && y == 0;
    }
};

int main() {
    Solution sol = Solution();
    string s = "GLRLGLLGLGRGLGL";
    bool res = sol.isRobotBounded(s);
    cout << res << endl;
    return 0;
}
