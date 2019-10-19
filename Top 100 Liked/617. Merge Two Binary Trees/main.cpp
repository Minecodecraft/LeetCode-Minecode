//
//  main.cpp
//  617. Merge Two Binary Trees
//
//  Created by 边俊林 on 2019/10/20.
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return NULL;
        TreeNode* newNode = t1 == NULL ? t2 : t1;
        int sum = 0;
        sum += t1 == NULL ? 0 : t1->val;
        sum += t2 == NULL ? 0 : t2->val;
        newNode->val = sum;
        newNode->left = mergeTrees(t1 ? t1->left : NULL, t2 ? t2->left : NULL);
        newNode->right = mergeTrees(t1 ? t1->right : NULL, t2 ? t2->right : NULL);
        return newNode;
    }
};

int main() {
    Solution sol = Solution();

    TreeNode* n11 = new TreeNode(1);
    TreeNode* n13 = new TreeNode(3);
    TreeNode* n12 = new TreeNode(2);
    TreeNode* n15 = new TreeNode(5);
    n11->left = n13; n11->right = n12;
    n13->left = n15;

    TreeNode* n22 = new TreeNode(2);
    TreeNode* n21 = new TreeNode(1);
    TreeNode* n23 = new TreeNode(3);
    TreeNode* n24 = new TreeNode(4);
    TreeNode* n27 = new TreeNode(7);
    n22->left = n21; n22->right = n23;
    n21->right = n24; n23->right = n27;

    auto res = sol.mergeTrees(n11, n22);
    cout << res->val << endl;

    return 0;
}
