//
//  main.cpp
//  124. Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int maxx = INT_MIN;
        solve(root, maxx);
        return maxx;
    }

private:
    int solve(TreeNode* pRoot, int& maxx) {
        int sum = pRoot->val, lsum = 0, rsum = 0;
        if (pRoot->left != NULL)
            lsum = max(lsum, solve(pRoot->left, maxx));
        if (pRoot->right != NULL)
            rsum = max(rsum, solve(pRoot->right, maxx));
        maxx = max(maxx, sum + lsum + rsum);
        return sum + max(lsum, rsum);
    }
};

int main() {
    Solution sol = Solution();

    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);
    n1->left = n2;
    n1->right = n3;

    int res = sol.maxPathSum(n1);
    cout << res << endl;

    return 0;
}
