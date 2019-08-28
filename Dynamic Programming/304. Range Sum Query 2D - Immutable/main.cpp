//
//  main.cpp
//  304. Range Sum Query 2D - Immutable
//
//  Created by 边俊林 on 2019/8/28.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/range-sum-query-2d-immutable/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() <= 0) return;
        lsum = vector<vector<int>> (matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for (int row = 1; row <= matrix.size(); ++row) {
            for (int col = 1; col <= matrix[0].size(); ++col) {
                lsum[row][col] = lsum[row][col-1] + matrix[row-1][col-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (lsum.size() <= 1) return 0;
        int res = 0;
        for (int i = row1+1; i <= row2+1; ++i) {
            res += lsum[i][col2+1] - lsum[i][col1];
        }
        return res;
    }

private:
    vector<vector<int>> lsum;
};

vector<vector<int>> mockDataFrom(vector<string> strs) {
    vector<vector<int>> res;
    for (auto str : strs) {
        vector<int> tmp;
        for (auto ch: str)
            tmp.push_back((int)ch);
        res.push_back(tmp);
    }
    return res;
}

int main() {
//    vector<vector<int>> matrix = {
//        {3, 0, 1, 4, 2},
//        {5, 6, 3, 2, 1},
//        {1, 2, 0, 1, 5},
//        {4, 1, 0, 1, 7},
//        {1, 0, 3, 0, 5}
//    };
    vector<vector<int>> matrix = {};
    NumMatrix sol = NumMatrix(matrix);
    /*
    sumRegion(2, 1, 4, 3) -> 8
    sumRegion(1, 1, 2, 2) -> 11
    sumRegion(1, 2, 2, 4) -> 12
     */
    int res = 0;
//    res = sol.sumRegion(2, 1, 4, 3);
//    cout << res << endl;
//    res = sol.sumRegion(1, 1, 2, 2);
//    cout << res << endl;
//    res = sol.sumRegion(1, 2, 2, 4);
//    cout << res << endl;
//    res = sol.sumRegion(1, 1, 1, 1);
//    cout << res << endl;

    return 0;
}
