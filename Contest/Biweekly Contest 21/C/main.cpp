//
//  main.cpp
//  C
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
public:
    int longestZigZag(TreeNode* root) {
        res = max(res, dfs(root->left, 1, 0));
        res = max(res, dfs(root->right, 1, 1));
        return res;
    }

private:
    int res = 0;
    map<pair<TreeNode*, int>, int> cache;

    // 0 left, 1 right
    int dfs(TreeNode* pNode, int depth, int dir) {
        if (pNode == NULL) return 0;
        pair<TreeNode*, int> key = {pNode, dir};
        if (cache.count(key))
            return cache[key];

        int cnt = 0;
        if (dir == 0) {
            res = max(res, dfs(pNode->left, 1, 0));
            cnt = dfs(pNode->right, depth+1, 1);
        } else {
            res = max(res, dfs(pNode->right, 1, 1));
            cnt = dfs(pNode->left, depth+1, 0);
        }

        return cache[key] = cnt + 1;
    }
};

int main() {
    Solution sol = Solution();
    return 0;
}
