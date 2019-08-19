//
//  main.cpp
//  95. Unique Binary Search Trees II
//
//  Created by 边俊林 on 2019/8/19.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
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
    vector<TreeNode*> generateTrees(int n) {
        if (n < 1) return {};
        return generateTreesCore(1, n);
    }

private:
    vector<TreeNode*> generateTreesCore(int beg, int end) {
        vector<TreeNode *> res;

        if (beg > end) res.push_back(0);
        else if (beg == end) res.push_back((new TreeNode(beg)));
        else {
            for (int i = beg; i <= end; ++i) {
                // root -> i
                vector<TreeNode *> lnodes = generateTreesCore(beg, i-1);
                vector<TreeNode *> rnodes = generateTreesCore(i+1, end);

                for (int j = 0; j < lnodes.size(); ++j) {
                    for (int k = 0; k < rnodes.size(); ++k) {
                        TreeNode *root = new TreeNode(i);
                        root->left = lnodes[j];
                        root->right = rnodes[k];
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 3;
    int n = 0;
    auto res = sol.generateTrees(n);
    cout << res[0]->val << endl;
    return 0;
}
