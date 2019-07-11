//
//  main.cpp
//  118. Pascal's Triangle
//
//  Created by Minecode on 2019/7/11.
//  Copyright © 2019 minecode. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/pascals-triangle/
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
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for (int i = 0; i < numRows; ++i) {
            if (i == 0) res.push_back({1});
            else if (i == 1) res.push_back({1, 1});
            else {
                vector<int> tmp;
                for (int j = 0; j <= i; ++j) {
                    if (j == 0) tmp.push_back(res[i-1][0]);
                    else if (j == i) tmp.push_back(res[i-1][i-1]);
                    else tmp.push_back(res[i-1][j-1] + res[i-1][j]);
                }
                res.push_back(tmp);
            }
        }
        return res;
    }
};

/// Tips:
//

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
    auto res = sol.generate(5);
    printVectors(res);
    
    return 0;
}
