//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2020/1/11.
//  Copyright © 2020 边俊林. All rights reserved.
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
    int sumEvenGrandparent(TreeNode* root) {
        int res = 0;
        if (root)
            sumup(root, NULL, NULL, res);
        return res;
    }

private:
    void sumup(TreeNode* pNode, TreeNode* fa, TreeNode* gp, int& res) {
        if (gp != NULL && (gp->val & 1) == 0)
            res += pNode->val;

        if (pNode->left)
            sumup(pNode->left, pNode, fa, res);
        if (pNode->right)
            sumup(pNode->right, pNode, fa, res);
    }
};

int main() {

    return 0;
}
