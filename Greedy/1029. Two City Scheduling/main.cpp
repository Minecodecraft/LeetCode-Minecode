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

// Solution 2: O(n) average with QuickSelection algorithm, beats 100%
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        quickSelect(costs, 0, costs.size()-1, costs.size()/2);
        int res = 0;
        for (int i = 0; i < costs.size()/2; ++i)
            res += costs[i][0] + costs[i+costs.size()/2][1];
        return res;
    }

private:
    void quickSelect(vector<vector<int>>& costs, int low, int high, int k) {
        int pivot = low + rand() % (high-low+1);
        swap(costs[high], costs[pivot]);
        int i = low, j = low;
        while (j < high) {
            if (costs[j][0]-costs[j][1] <= costs[high][0]-costs[high][1])
                swap(costs[i++], costs[j]);
            ++j;
        }
        swap(costs[i], costs[j]);
        if (i == high-k+1) return;
        else if (i > high-k+1) quickSelect(costs, low, i-1, k-(high-i+1));
        else quickSelect(costs, i+1, high, k);
    }
};

int main() {
    Solution sol = Solution();

    vector<vector<int>> mat = {
        {10, 20}, {30, 200}, {400, 50}, {30, 20}
    };
    int res = sol.twoCitySchedCost(mat);
    cout << res << endl;
    return 0;
}
