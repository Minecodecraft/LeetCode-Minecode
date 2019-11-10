//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/11/10.
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
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> path (2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                path[0][i] = 1;
                path[1][i] = 1;
                --upper, --lower;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 1) {
                if (upper > lower) {
                    path[0][i] = 1;
                    --upper;
                } else {
                    path[1][i] = 1;
                    --lower;
                }
            }
        }
        if (upper == 0 && lower == 0)
            return path;
        return vector<vector<int>>();
    }
};

int main() {
    Solution sol = Solution();
    vector<int> cols = {
        1, 1, 1
//        2,0,2,1,1,2,2,0,1,1,1,0,0,0,0,2,1,2,2,2,1,1,0,0,0,0,1,2,1,0,1,0,2,0,0,0,0,2,1,1,2,1,1,0,0,1,0,0,1,1,2,0,1,1,1,2,1,0,0,1,1,1,2,2,1,0,0,1,1,1,0,2,1,2,1,0,1,2,0,2,2,1,0,1,1,1,2,0,0,0,1,2,2,0,0,1,1,2,1,2
    };
    int up = 2, lo = 1;
//    int up = 53, lo = 82;
    auto res = sol.reconstructMatrix(up, lo, cols);
    cout << res.size() << endl;
    return 0;
}
