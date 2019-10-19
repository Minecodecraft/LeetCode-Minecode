//
//  main.cpp
//  543. Diameter of Binary Tree
//
//  Created by 边俊林 on 2019/10/19.
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
    int diameterOfBinaryTree(TreeNode* root) {
        maxlen(root);
        return curmax;
    }

private:
    int curmax = 0;
    int maxlen(TreeNode* root) {
        if (root == NULL) return 0;
        int llen = root->left == NULL ? 0 : maxlen(root->left);
        int rlen = root->right == NULL ? 0 : maxlen(root->right);

        curmax = max(curmax, llen + rlen);
        return max(llen, rlen) + 1;
    }
};

int main() {
    Solution sol = Solution();

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);

    n1->left = n2; n1->right = n3;
    n2->left = n4; n2->right = n5;

//    n1->left = n2;

    int res = sol.diameterOfBinaryTree(n1);
    cout << res << endl;

    return 0;
}
