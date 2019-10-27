//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2019/10/27.
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
class CustomFunction {
public:
    // Returns f(x, y) for any given positive integers x and y.
    // Note that f(x, y) is increasing with respect to both x and y.
    // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
    int f(int x, int y);
};

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> res;
        for (int i = 1; i <= z; ++i) {
            for (int j = 1; j <= z; ++j) {
                int sum = customfunction.f(i, j);
                if (sum == z)
                    res.push_back({i, j});
                else if (sum > z)
                    break;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
