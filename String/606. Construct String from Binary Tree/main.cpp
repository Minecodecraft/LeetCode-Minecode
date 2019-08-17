//
//  main.cpp
//  606. Construct String from Binary Tree
//
//  Created by 边俊林 on 2019/8/17.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/construct-string-from-binary-tree/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sstream>
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
    string tree2str(TreeNode* t) {
        if (t == NULL) return "";
        string res;
        traverseCore(t, res);
        return res;
    }

private:
    void traverseCore(TreeNode* root, string& res) {
        res += to_string(root->val);
        if (root->left != NULL) {
            res += "(";
            traverseCore(root->left, res);
            res += ")";
        } else if (root->right != NULL) {
            res += "()";
        }
        if (root->right != NULL) {
            res += "(";
            traverseCore(root->right, res);
            res += ")";
        }
    }
};

int main() {
    Solution sol = Solution();
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    n1->left = n2;
    n1->right = n3;
    n2->right = n4;
    auto root = n1;
    auto res = sol.tree2str(root);
    cout << res << endl;
    return 0;
}
