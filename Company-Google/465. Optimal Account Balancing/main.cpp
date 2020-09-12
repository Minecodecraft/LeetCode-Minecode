//
//  main.cpp
//  465. Optimal Account Balancing
//
//  Created by Jaylen Bian on 9/12/20.
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
class Solution {
    int dfs(int idx, vector<int>& debt) {
        while (idx < debt.size() && debt[idx] == 0)
            ++idx;

        int tot = INT_MAX, prev = INT_MIN;
        for (int i = idx+1; i < debt.size(); ++i) {
            if (debt[i] != prev && debt[i] * debt[idx] < 0) {
                debt[i] += debt[idx];
                tot = min(tot, 1+dfs(idx+1, debt));
                debt[i] -= debt[idx];
                prev = debt[i];
            }
        }
        return tot == INT_MAX ? 0 : tot;
    }

public:
    int minTransfers(vector<vector<int>>& trcs) {
        // debt[i] > 0, i should gives others
        // debt[i] < 0, i should recive from others
        unordered_map<int, int> moves;
        for (auto& trc: trcs) {
            moves[trc[0]] -= trc[2];
            moves[trc[1]] += trc[2];
        }

        vector<int> debt;
        for (auto& move: moves) {
            if (move.second)
                debt.push_back(move.second);
        }
        return dfs(0, debt);
    }
};

int main() {

    return 0;
}
