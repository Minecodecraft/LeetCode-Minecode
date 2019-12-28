//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/12/28.
//  Copyright © 2019 边俊林. All rights reserved.
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
typedef long long ll;
typedef pair<int,int> P;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 0x3f3f3f3f
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int maxsum = 0;
        while (q.size()) {
            int sz = q.size(), sum = 0;
            while (sz--) {
                TreeNode* pNode = q.front();
                q.pop();

                sum += pNode->val;
                if (pNode->left != NULL) q.push(pNode->left);
                if (pNode->right != NULL) q.push(pNode->right);
            }
            maxsum = sum;
        }
        return maxsum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solu

    return 0;
}
