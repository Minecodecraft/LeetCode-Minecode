//
//  main.cpp
//  1094. Car Pooling
//
//  Created by 边俊林 on 2019/11/8.
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
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> points;
        for (auto& trip: trips) {
            points.push_back(make_pair(trip[1], trip[0]));
            points.push_back(make_pair(trip[2], -trip[0]));
        }
        sort(begin(points), end(points), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first || a.first == b.first && a.second < b.second;
        });
        int sum = 0;
        for (int i = 0; i < points.size(); ++i) {
            sum += points[i].second;
            if (sum > capacity) return false;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
        {2,1,5},{3,3,7}
    };
    int capacity = 4;
    return 0;
}
