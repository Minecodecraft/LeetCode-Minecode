//
//  main.cpp
//  298. Binary Tree Longest Consecutive Sequence
//
//  Created by Jaylen Bian on 7/26/20.
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution 1: Ungly
/*
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {root->val, 1}});
        int res = 0;
        while (q.size()) {
            auto pir = q.front(); q.pop();
            res = max(res, pir.second.second);
            TreeNode* node = pir.first;
            int val = pir.second.first;
            if (node->left) {
                q.push({node->left, {node->left->val, node->left->val==val+1 ? pir.second.second+1: 1}});
            }
            if (node->right) {
                q.push({node->right, {node->right->val, node->right->val==val+1 ? pir.second.second+1: 1}});
            }
        }
        return res;
    }
};
 */

// Solution 2: Concise way
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        return search(root, NULL, 0);
    }

private:
    int search(TreeNode* root, TreeNode* parent, int len) {
        if (!root) return len;
        len = (parent && root->val == parent->val + 1) ? len+1 : 1;
        return max(len, max(search(root->left, root, len), search(root->right, root, len)));
    }
};

int main() {

    return 0;
}
