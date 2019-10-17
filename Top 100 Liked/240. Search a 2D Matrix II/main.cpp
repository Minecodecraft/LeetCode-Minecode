//
//  main.cpp
//  240. Search a 2D Matrix II
//
//  Created by 边俊林 on 2019/10/17.
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
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
        if (cols == 0) return false;

        for (int i = 0; i < rows && matrix[i][0] <= target; ++i) {
            auto it = lower_bound(matrix[i].begin(), matrix[i].end(), target);
            if (it != matrix[i].end() && *it == target) return true;
        }

        return false;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {1,   4,  7, 11, 15},
//        {2,   5,  8, 12, 19},
//        {3,   6,  9, 16, 22},
//        {10, 13, 14, 17, 24},
//        {18, 21, 23, 26, 30}
        {}
    };
//    int target = 5;
    int target = 20;
    bool res = sol.searchMatrix(mat, target);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
