//
//  main.cpp
//  108. Convert Sorted Array to Binary Search Tree
//
//  Created by 边俊林 on 2019/10/20.
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeTree(nums, 0, nums.size()-1);
    }

private:
    TreeNode* makeTree(vector<int>& nums, int s, int e) {
        if (s > e) return NULL;
        int mid = s + (e - s) / 2;
        TreeNode* pRoot = new TreeNode(nums[mid]);
        pRoot->left = makeTree(nums, s, mid-1);
        pRoot->right = makeTree(nums, mid+1, e);
        return pRoot;
    }
};

int main() {
    Solution sol = Solution();

    vector<int> nums = {
        -10,-3,0,5,9
    };

    auto res = sol.sortedArrayToBST(nums);
    cout << res->val << endl;

    return 0;
}
