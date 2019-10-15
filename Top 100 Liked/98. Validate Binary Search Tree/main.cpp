//
//  main.cpp
//  98. Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        queue<pair<TreeNode*, pair<long, long>>> q;
        if (root != NULL) q.push(make_pair(root, make_pair(LONG_MIN, LONG_MAX)));
        while (q.size()) {
            auto cur = q.front(); q.pop();
            auto pNode = cur.first;
            auto range = cur.second;
            if (pNode->left != NULL) {
                pair<long, long> newrange = make_pair(range.first, min((long)pNode->val, range.second));
                if (pNode->left->val <= newrange.first || pNode->left->val >= newrange.second) return false;
                q.push(make_pair(pNode->left, newrange));
            }
            if (pNode->right != NULL) {
                pair<long, long> newrange = make_pair(max((long)pNode->val, range.first), range.second);
                if (pNode->right->val <= newrange.first || pNode->right->val >= newrange.second) return false;
                q.push(make_pair(pNode->right, newrange));
            }
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
//    TreeNode* n10 = new TreeNode(10);
//    TreeNode* n5 = new TreeNode(5);
//    TreeNode* n15 = new TreeNode(15);
//    TreeNode* n6 = new TreeNode(6);
//    TreeNode* n20 = new TreeNode(20);
//    n10->left = n5;
//    n10->right = n15;
//    n15->left = n6;
//    n15->right = n20;
//    bool res = sol.isValidBST(n10);

//    TreeNode* n2 = new TreeNode(2);
//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n3 = new TreeNode(3);
//    n2->left = n1;
//    n2->right = n3;
//    bool res = sol.isValidBST(n2);

//    TreeNode* n5 = new TreeNode(5);
//    TreeNode* n1 = new TreeNode(1);
//    TreeNode* n4 = new TreeNode(4);
//    TreeNode* n3 = new TreeNode(3);
//    TreeNode* n6 = new TreeNode(6);
//    n5->left = n1;
//    n5->right = n4;
//    n4->left = n3;
//    n4->right = n6;
//    bool res = sol.isValidBST(n5);

    TreeNode* n1 = new TreeNode(INT_MIN);
    TreeNode* n2 = new TreeNode(INT_MAX);
    n1->right = n2;
    bool res = sol.isValidBST(n1);

    cout << (res ? "true" : "false") << endl;

    return 0;
}
