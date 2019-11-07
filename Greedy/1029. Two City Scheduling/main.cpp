//
//  main.cpp
//  1029. Two City Scheduling
//
//  Created by 边俊林 on 2019/11/7.
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
// Solution 1: O(nlogn) with sort, 8ms, beats only 44%
/*
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs), end(costs), [](vector<int>& a, vector<int>& b) {
            return a[1]-a[0] > b[1]-b[0];
        });
        int res = 0;
        for (int i = 0; i < costs.size()/2; ++i) {
            res += costs[i][0] + costs[i+costs.size()/2][1];
        }
        return res;
    }
};
 */

// Solution 2: O(n)
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {

    }
};

int main() {

    return 0;
}
