//
//  main.cpp
//  46. Permutations
//
//  Created by 边俊林 on 2019/10/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    using vvi = vector<vector<int>>;
    vector<vector<int>> permute(vector<int>& nums) {
        vvi res;
        vector<bool> vis (nums.size(), false);
        vector<int> path;
        for (int i = 0; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            vis[i] = true;
            solve(res, nums, vis, 1, path);
            path.pop_back();
            vis[i] = false;
        }
        return res;
    }

private:
    void solve(vvi& res, vector<int>& nums, vector<bool>& vis, int cnt, vector<int>& path) {
        if (cnt == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i]) continue;
            path.push_back(nums[i]);
            vis[i] = true;
            solve(res, nums, vis, cnt+1, path);
            path.pop_back();
            vis[i] = false;
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {1, 2, 3};
    auto res = sol.permute(nums);
    cout << res.size() << endl;
    return 0;
}
