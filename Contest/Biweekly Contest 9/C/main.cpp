//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/9/21.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
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
    int smallestCommonElement(vector<vector<int>>& mat) {
        for (int i = 1; i <= 1e4; ++i) {
            bool flag = true;
            for (int j = 0; j < mat.size(); ++j) {
                auto arr = mat[j];
                auto it = lower_bound(arr.begin(), arr.end(), i);
                if (it == arr.end() || *it != i) {
                    flag = false; break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
        {1, 2, 3, 4, 5},
        {2, 4, 5, 9, 10},
        {3, 5, 7, 9, 11},
        {1, 3, 5, 7, 9}
    };
    cout << sol.smallestCommonElement(mat) << endl;
    return 0;
}
