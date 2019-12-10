//
//  main.cpp
//  1161. Maximum Level Sum of a Binary Tree
//
//  Created by 边俊林 on 2019/12/10.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int res = 0, maxsum = INT_MIN, idx = 0;
        while (q.size()) {
            ++idx;
            int sz = q.size(), sum = 0;
            while (sz--) {
                auto& pNode = q.front();
                sum += pNode->val;
                if (pNode->left != NULL)
                    q.push(pNode->left);
                if (pNode->right != NULL)
                    q.push(pNode->right);
                q.pop();
            }
            if (sum > maxsum) {
                res = idx;
                maxsum = sum;
            }
        }
        return res;
    }
};

int main() {

    return 0;
}
