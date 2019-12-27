//
//  main.cpp
//  308. Range Sum Query 2D - Mutable
//
//  Created by 边俊林 on 2019/12/27.
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
// Solution 1: Prefix Sum, 12ms, 13.8MB
/*
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size(), m = n == 0 ? 0 : matrix[0].size();
        sum = vector<vector<int>> (n, vector<int> (m+1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                sum[i][j+1] = sum[i][j] + matrix[i][j];
            }
        }
    }

    void update(int row, int col, int val) {
        int dif = val - (sum[row][col+1] - sum[row][col]);
        for (int i = col+1; i <= m; ++i)
            sum[row][i] += dif;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int tot = 0;
        for (int i = row1; i <= row2; ++i) {
            tot += sum[i][col2+1] - sum[i][col1];
        }
        return tot;
    }

private:
    int n, m;
    vector<vector<int>> sum;
};
 */



int main() {
    vector<vector<int>> mat = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix sol = NumMatrix(mat);
    cout << sol.sumRegion(2, 1, 4, 3) << endl;
    sol.update(3, 2, 2);
    cout << sol.sumRegion(2, 1, 4, 3) << endl;

    return 0;
}
