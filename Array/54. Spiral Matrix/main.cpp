//
//  main.cpp
//  54. Spiral Matrix
//
//  Created by 边俊林 on 2018/7/19.
//  Copyright © 2018 minecode. All rights reserved.
//

/* -------------------------------------------------------- *\
 https://leetcode-cn.com/problems/spiral-matrix/description/
\* -------------------------------------------------------- */

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
// Simulation algorithm, use four flag to record the min and max index of column and row
// then use them to determine the range to traverse

/// Tips:
//

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return vector<int>();
        int n = (int)matrix.size(), m = (int)matrix[0].size();
        vector<int> res = vector<int>(n*m);
        int p = 0;
        int minx = 0, maxx = m-1, miny = 0, maxy = n-1;
        while (true) {
            for (int col = minx; col <= maxx; ++col) { res[p++] = matrix[miny][col]; }
            if (++miny > maxy) break;
            
            for (int row = miny; row <= maxy; ++row) { res[p++] = matrix[row][maxx]; }
            if (--maxx < minx) break;
            
            for (int col = maxx; col >= minx; --col) { res[p++] = matrix[maxy][col]; }
            if (--maxy < miny) break;
            
            for (int row = maxy; row >= miny; --row) { res[p++] = matrix[row][minx]; }
            if (++minx > maxx) break;
        }
        return res;
    }
};

void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}
void printVectors(vector<vector<int>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    
    vector<int> v1 {1, 2, 3, 4};
    vector<int> v2 {5, 6, 7, 8};
    vector<int> v3 {9, 10, 11, 12};
    vector<vector<int>> v = {v1, v2, v3};
    
    auto res = sol.spiralOrder(v);
    printVector(res);
    
    return 0;
}
