//
//  main.cpp
//  437. Path Sum III
//
//  Created by 边俊林 on 2019/10/18.
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
    int pathSum(TreeNode* root, int sum) {
        int res = 0;
        search(root, 0, sum, res);
        return res;
    }

private:
    unordered_set<TreeNode*> vis;

    void search(TreeNode* root, int sum, int tar, int& cnt) {
        if (root == NULL) return;

        sum += root->val;
        if (sum == tar)
            ++cnt;
        if (root->left != NULL) {
            search(root->left, sum, tar, cnt);
            if (vis.count(root) == 0)
                search(root->left, 0, tar, cnt);
        }
        if (root->right != NULL) {
            search(root->right, sum, tar, cnt);
            if (vis.count(root) == 0)
                search(root->right, 0, tar, cnt);
        }
        vis.insert(root);
    }
};

int main() {
    Solution sol = Solution();

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(5);
    n1->right = n2;
    n2->right = n3;
    n3->right = n4;
    n4->right = n5;

    int res = sol.pathSum(n1, 3);
    cout << res << endl;

    return 0;
}
