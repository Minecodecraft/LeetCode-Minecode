//
//  main.cpp
//  103. Binary Tree Zigzag Level Order Traversal
//
//  Created by 边俊林 on 2019/9/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzagCore(root, 1, res);
        for (int i = 1; i < res.size(); i += 2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }

private:
    void zigzagCore(TreeNode* pRoot, int level, vector<vector<int>>& path) {
        if (pRoot == NULL) return;
        if (path.size() < level) path.push_back({});
        path[level-1].push_back(pRoot->val);
        if (pRoot->left != NULL)
            zigzagCore(pRoot->left, level+1, path);
        if (pRoot->right != NULL)
            zigzagCore(pRoot->right, level+1, path);
    }
};

int main() {
    Solution sol = Solution();
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n9 = new TreeNode(9);
    TreeNode* n20 = new TreeNode(20);
    TreeNode* n15 = new TreeNode(15);
    TreeNode* n7 = new TreeNode(7);
    n3->left = n9;
    n3->right = n20;
    n20->left = n15;
    n20->right = n7;
    auto res = sol.zigzagLevelOrder(n3);
    cout << res.size() << endl;
    return 0;
}
