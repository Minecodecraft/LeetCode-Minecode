//
//  main.cpp
//  39. Combination Sum
//
//  Created by 边俊林 on 2018/7/13.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ---------------------------------------------------------- *\
 https://leetcode-cn.com/problems/combination-sum/description/
\* ---------------------------------------------------------- */

#include <map>
#include <set>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
// Use DFS(Depth First Search) to search search vertically, if can reach the target, just push to the answer,
// if not, just return to your start point and begin next search.

/// Tips:
// DFS is purpose to search vertically first, which means depth first;
// and BFS is purpose to search horizontally first, which means breadth first.

class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    int n;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return res;
        n = (int)candidates.size();
        dfs(0, 0, target, candidates);
        return res;
    }
    
    void dfs(int start, int sum, int target, vector<int>& candidates) {
        if (sum == target) {
            res.push_back(tmp);
        } else if (sum > target) {
            return;
        } else {
            for (int i = start; i < n; ++i) {
                tmp.push_back(candidates[i]);
                dfs(i, sum+candidates[i], target, candidates);
                tmp.pop_back();
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
    
    int arr[] = {2, 3, 6, 7};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    int target = 7;
    
    auto res = sol.combinationSum(v, target);
    printVectors(res);
    
    return 0;
}
