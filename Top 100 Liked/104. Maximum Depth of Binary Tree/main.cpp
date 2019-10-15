//
//  main.cpp
//  104. Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != NULL) q.push(root);
        int cnt = 0;
        while (q.size()) {
            cnt++;
            int sz = q.size();
            while (sz--) {
                auto pNode = q.front(); q.pop();

                if (pNode->left != NULL)
                    q.push(pNode->left);
                if (pNode->right != NULL)
                    q.push(pNode->right);
            }
        }
        return cnt;
    }
};

int main() {

    return 0;
}
