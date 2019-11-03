//
//  main.cpp
//  874. Walking Robot Simulation
//
//  Created by 边俊林 on 2019/11/3.
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
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<pair<int, int>, pair_hash> obs;
        for (auto& curobs: obstacles)
            obs.emplace(curobs[0], curobs[1]);
        
        int cd = 0, res = 0, x = 0, y = 0;
        for (int i = 0; i < commands.size(); ++i) {
            if (commands[i] == -2)
                cd--;
            else if (commands[i] == -1)
                cd++;
            else {
                for (int j = 0; j < commands[i]; ++j) {
                    int tx = x + dir[cd][0], ty = y + dir[cd][1];
                    if (obs.count(make_pair(tx, ty))) break;
                    x = tx;
                    y = ty;
                }
                res = max(res, x*x + y*y);
            }
            cd = (cd + 4) % 4;
        }
        return res;
    }
    
private:
    vector<vector<int>> dir = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };
    
    struct pair_hash {
        size_t operator() (const pair<int, int>& pir) const {
            return (size_t)pir.first * 80000  + (size_t)pir.second;
        }
    };
};

int main() {
    Solution sol = Solution();
    vector<int> cmds = {
//        4,-1,3
        4,-1,4,-2,4
    };
    vector<vector<int>> obs = {
        {2, 4}
    };
    int res = sol.robotSim(cmds, obs);
    cout << res << endl;
    return 0;
}
