//
//  main.cpp
//  48. Rotate Image
//
//  Created by 边俊林 on 2018/7/18.
//  Copyright © 2018 minecode. All rights reserved.
//

/* -------------------------------------------------------- *\
 https://leetcode-cn.com/problems/rotate-image/description/
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
// The clockwise rotate, we can reverse the row, and then swap the symmetry

/// Tips:
//

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i+1; j < matrix[i].size(); ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

// Tool Function List
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
    
    vector<int> v1 {5, 1, 9, 11};
    vector<int> v2 {2, 4, 8, 10};
    vector<int> v3 {13, 3, 6, 7};
    vector<int> v4 {15, 14, 12, 16};
    vector<vector<int>> v = {v1, v2, v3, v4};
    
    sol.rotate(v);
    printVectors(v);
    
    return 0;
}
