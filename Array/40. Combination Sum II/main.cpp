//
//  main.cpp
//  40. Combination Sum II
//
//  Created by 边俊林 on 2018/7/16.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------------------ *\
 https://leetcode-cn.com/problems/combination-sum-ii/description/
\* ------------------------------------------------------------ */

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
// Same as 39. Combination Sum, but this question should pass the duplicates.

/// Tips:
//

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    int n;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return res;
        
        sort(candidates.begin(), candidates.end());
        n = (int)candidates.size();
        dfs(0, 0, target, candidates);
        return res;
    }
private:
    void dfs(int start, int sum, int target, vector<int>& candidates) {
        if (sum == target) {
            res.push_back(tmp);
        } else if (sum > target) {
            return;
        } else {
            for (int i = start; i < n; ++i) {
                tmp.push_back(candidates[i]);
                dfs(i+1, sum+candidates[i], target, candidates);
                tmp.pop_back();
                while(candidates[i] == candidates[i+1]) ++i;
            }
        }
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
    
    int arr[] = {10, 1, 2, 7, 6, 1, 5};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    int target = 8;
    
    auto res = sol.combinationSum2(v, target);
    printVectors(res);
    
    return 0;
}
