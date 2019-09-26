//
//  main.cpp
//  94. Binary Tree Inorder Traversal
//
//  Created by 边俊林 on 2019/9/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversalCore(root, res);
        return res;
    }

private:
    void traversalCore(TreeNode* pRoot, vector<int>& path) {
        if (pRoot == NULL) return;
        traversalCore(pRoot->left, path);
        path.push_back(pRoot->val);
        traversalCore(pRoot->right, path);
    }
};

int main() {
    Solution sol = Solution();
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->right = n2;
    n2->left = n3;
    vector<int> res = sol.inorderTraversal(n1);
    cout << res.size() << endl;
    return 0;
}
