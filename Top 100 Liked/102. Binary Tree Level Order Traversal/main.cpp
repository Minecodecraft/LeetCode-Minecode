//
//  main.cpp
//  102. Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root != NULL) q.push(root);
        while (q.size()) {
            int sz = q.size();
            vector<int> tmp;
            while (sz--) {
                auto pNode = q.front(); q.pop();
                tmp.push_back(pNode->val);

                if (pNode->left != NULL)
                    q.push(pNode->left);
                if (pNode->right != NULL)
                    q.push(pNode->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main() {

    return 0;
}
