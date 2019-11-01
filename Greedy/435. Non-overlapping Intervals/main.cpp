//
//  main.cpp
//  435. Non-overlapping Intervals
//
//  Created by 边俊林 on 2019/11/1.
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
    int eraseOverlapIntervals(vector<vector<int>>& ints) {
        sort(ints.begin(), ints.end(), [](vector<int>& a, vector<int>& b) {
            return a[0]<b[0] || a[0]==b[0] && a[1] < b[1];
        });
        int cnt = 0, back = 0;
        for (auto& ran: ints) {
            if (ran[0] >= back) {
                ++cnt;
                back = ran[1];
            }
        }
        return ints.size() - cnt;
    }
};

int main() {

    return 0;
}
