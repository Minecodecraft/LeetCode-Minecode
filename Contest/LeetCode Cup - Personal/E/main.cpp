//
//  main.cpp
//  E
//
//  Created by Jaylen Bian on 4/18/20.
//  Copyright © 2020 Jaylen Bian. All rights reserved.
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
    double minimalExecTime(TreeNode* root) {
        if (!root)
            return 0;

        int MAXN = 1010, tot = 0;
        vector<TreeNode *> nodes (MAXN, NULL);
        vector<int> ind (MAXN, 0);
        vector<int> nxt (MAXN, -1);

        vector<TreeNode *> arr = {root};
        while (arr.size()) {
            vector<TreeNode *> newArr;
            for (int i = 0; i < arr.size(); ++i) {
                nodes[tot] = arr[i];
                if (arr[i]->left) {
                    ++ind[tot];
                    nxt[tot - i + arr.size() + newArr.size()] = tot;
                    newArr.push_back(arr[i]->left);
                }
                if (arr[i]->right) {
                    ++ind[tot];
                    nxt[tot - i + arr.size() + newArr.size()] = tot;
                    newArr.push_back(arr[i]->right);
                }
                ++tot;
            }
            if (newArr.empty())
                break;
            arr = newArr;
        }

        queue<TreeNode *> q;
        for (auto& node: arr) q.push(node);
        while (q.size()) {
            
        }
    }
};

int main() {

    return 0;
}
