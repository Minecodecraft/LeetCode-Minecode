//
//  main.cpp
//  222. Count Complete Tree Nodes
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int getDepth(TreeNode *node) {
        int cnt = 0;
        while (node) {
            node = node->left;
            ++cnt;
        }
        return cnt;
    }

    bool isExist(TreeNode* node, int d, int idx) {
        int l = 0, r = pow(2, d) - 1;
        for (int i = 0; i < d; ++i) {
            int mid = l + (r - l) / 2;
            if (idx <= mid) {
                node = node->left;
                r = mid;
            } else {
                node = node->right;
                l = mid + 1;
            }
        }
        return node != NULL;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int d = getDepth(root)-1;

        int cnt = pow(2, d);
        int l = 0, r = cnt;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (isExist(root, d, mid))
                l = mid + 1;
            else
                r = mid;
        }
        return cnt - 1 + l;
    }
};

int main() {

    return 0;
}
