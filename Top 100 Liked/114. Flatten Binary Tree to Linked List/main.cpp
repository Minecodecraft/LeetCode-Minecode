//
//  main.cpp
//  114. Flatten Binary Tree to Linked List
//
//  Created by 边俊林 on 2019/10/15.
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
    void flatten(TreeNode* root) {
        TreeNode* pList = new TreeNode(-1);
        if (root == NULL) return;
        traverse(root, pList);
        root = pList->right;
    }

private:
    TreeNode* traverse(TreeNode* pRoot, TreeNode* pList) {
        TreeNode* pLeft = pRoot->left, *pRight = pRoot->right;
        pRoot->left = pRoot->right = NULL;
        pList->right = pRoot;
        pList = pList->right;

        if (pLeft != NULL)
            pList = traverse(pLeft, pList);
        if (pRight != NULL)
            pList = traverse(pRight, pList);
        return pList;
    }
};

int main() {
    Solution sol = Solution();

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n21 = new TreeNode(2);
    TreeNode* n22 = new TreeNode(5);
    TreeNode* n31 = new TreeNode(3);
    TreeNode* n32 = new TreeNode(4);
    TreeNode* n33 = new TreeNode(6);
    n1->left = n21; n1->right = n22;
    n21->left = n31; n21->right = n32;
    n22->right = n33;

//    sol.flatten(n1);
    sol.flatten(NULL);
    cout << n1->val << endl;

    return 0;
}
