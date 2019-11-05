//
//  main.cpp
//  944. Delete Columns to Make Sorted
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
        int res = 0;
        int rows = A.size(), cols = rows ? A[0].size() : 0;
        for (int col = 0; col < cols; ++col) {
            for (int r = 1; r < rows; ++r) {
                if (A[r][col] < A[r-1][col]) {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
