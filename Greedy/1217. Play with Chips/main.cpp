//
//  main.cpp
//  1217. Play with Chips
//
//  Created by 边俊林 on 2019/11/9.
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
    int minCostToMoveChips(vector<int>& chips) {
        int cnt = 0;
        for (int& chip: chips)
            cnt += chip & 1 ? 1 : 0;
        return min(cnt, (int)chips.size()-cnt);
    }
};

int main() {

    return 0;
}
