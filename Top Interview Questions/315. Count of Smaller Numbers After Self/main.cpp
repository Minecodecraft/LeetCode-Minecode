//
//  main.cpp
//  315. Count of Smaller Numbers After Self
//
//  Created by 边俊林 on 2019/10/28.
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
// Solution 1: Binary Search, O(nlogn)
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> tmp, res(nums.size(), 0);
        for (int i = nums.size()-1; i >= 0; --i) {
            auto it = lower_bound(tmp.begin(), tmp.end(), nums[i]);
            res[i] = it - tmp.begin();
            tmp.insert(it, nums[i]);
        }
        return res;
    }
};
 */

// Solution 2: BST Solution, O(nlogn), Worst is O(n^2) since the tree is not balanced
/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res (nums.size());
        TreeNode* root = NULL;
        for (int i = nums.size()-1; i >= 0; --i) {
            res[i] = insert(root, nums[i]);
        }
        return res;
    }

private:
    struct TreeNode {
        int smaller = 0, val = 0;
        TreeNode* left = NULL, * right = NULL;

        TreeNode(int val)
        : val(val) { }
    };

    int insert(TreeNode*& node, int val) {
        if (node == NULL) {
            node = new TreeNode(val);
            return 0;
        }
        if (node->val > val) {
            node->smaller++;
            return insert(node->left, val);
        }
        return insert(node->right, val) + node->smaller + (node->val < val ? 1 : 0);
    }
};
 */

// Solution 3:


int main() {
    Solution sol = Solution();
    vector<int> nums = {
        5, 2, 6, 1
//        -1, -1
    };
    auto res = sol.countSmaller(nums);
    for_each(res.begin(), res.end(), [](int& ele) { cout << ele << ","; });
    cout << endl;
    return 0;
}
