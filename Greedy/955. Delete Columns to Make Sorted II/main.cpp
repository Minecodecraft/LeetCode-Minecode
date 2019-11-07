//
//  main.cpp
//  955. Delete Columns to Make Sorted II
//
//  Created by 边俊林 on 2019/11/5.
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
    int minDeletionSize(vector<string>& A) {
        int rows = A.size(), cols = rows ? A[0].size() : 0;
        vector<bool> larger (rows-1, false);
        int res = 0;
        for (int c = 0; c < cols; ++c) {
            int r;
            for (r = 0; r < rows-1; ++r) {
                if (!larger[r] && A[r][c] > A[r+1][c]) {
                    ++res;
                    break;
                }
            }
            if (r == rows-1) {
                for (r = 0; r < rows-1; ++r) {
                    larger[r] = larger[r] || A[r][c] < A[r+1][c];
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
