//
//  main.cpp
//  145. Binary Tree Postorder Traversal
//
//  Created by 边俊林 on 2019/9/26.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traversalCore(root, res);
        return res;
    }

private:
    void traversalCore(TreeNode* pRoot, vector<int>& path) {
        if (pRoot == NULL) return;
        traversalCore(pRoot->left, path);
        traversalCore(pRoot->right, path);
        path.push_back(pRoot->val);
    }
};

int main() {

    return 0;
}
