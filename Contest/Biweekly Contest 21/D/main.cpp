//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2020/3/7.
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    struct Result {
        bool isBST;
        int sum;
    };

    int res = 0;
    Result dfs(TreeNode *pNode) {
        if (pNode == NULL) return {false, 0};

        int sum = pNode->val;
        Result rstl = dfs(pNode->left);
        Result rstr = dfs(pNode->right);
        sum += rstl.sum;
        sum += rstr.sum;

        if ((pNode->left && !rstl.isBST) || (pNode->right && !rstr.isBST))
            return {false, 0};

        if (pNode->left && pNode->left->val >= pNode->val)
            return {false, pNode->val};
        if (pNode->right && pNode->right->val <= pNode->val)
            return {false, pNode->val};

        res = max(res, sum);
        return {true, sum};
    }

public:
    int maxSumBST(TreeNode* root) {
        if (root == NULL) return 0;
        dfs(root);
        return res;
    }
};

int main() {
    return 0;
}
