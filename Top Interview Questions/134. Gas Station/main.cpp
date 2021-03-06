//
//  main.cpp
//  134. Gas Station
//
//  Created by 边俊林 on 2019/10/20.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
// Solution 1: O(n^2) solution
/*
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            int totgas = 0;
            for (int j = 0; j < n; ++j) {
                int idx = (i + j) % n;
                totgas += gas[idx];
                totgas -= cost[idx];
                if (totgas < 0)
                    break;
            }
            if (totgas >= 0) return i;
        }
        return -1;
    }
};
 */

// Solution 2: O(n) solution
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int s = n-1, e = 0;
        int totgas = gas[s] - cost[s];
        while (s > e) {
            if (totgas >= 0) {
                totgas += gas[e] - cost[e];
                ++e;
            } else {
                --s;
                totgas += gas[s] - cost[s];
            }
        }
        return totgas >= 0 ? s : -1;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> gas = {
        1, 2, 3, 4, 5
//        2, 3, 4
    };
    vector<int> cost = {
        3, 4, 5, 1, 2
//        3, 4, 3
    };
    int res = sol.canCompleteCircuit(gas, cost);
    cout << res << endl;
    return 0;
}
