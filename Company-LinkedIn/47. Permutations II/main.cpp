//
//  main.cpp
//  47. Permutations II
//
//  Created by 边俊林 on 2020/1/16.
//  Copyright © 2020 边俊林. All rights reserved.
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        vector<int> path;
        vector<bool> vis (nums.size(), false);
        dfs(nums, res, path, vis);
        return res;
    }

private:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& vis) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !vis[i-1]) continue;
            vis[i] = true;
            path.push_back(nums[i]);
            dfs(nums, res, path, vis);
            path.pop_back();
            vis[i] = false;
        }
    }
};

int main() {

    return 0;
}
