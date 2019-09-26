//
//  main.cpp
//  144. Binary Tree Preorder Traversal
//
//  Created by 边俊林 on 2019/9/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/binary-tree-preorder-traversal/
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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversalCore(root, res);
        return res;
    }

private:
    void traversalCore(TreeNode* pRoot, vector<int>& path) {
        if (pRoot == NULL) return;
        path.push_back(pRoot->val);
        traversalCore(pRoot->left, path);
        traversalCore(pRoot->right, path);
    }
};

int main() {

    return 0;
}
