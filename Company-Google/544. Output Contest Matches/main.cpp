 //
//  main.cpp
//  544. Output Contest Matches
//
//  Created by Jaylen Bian on 1/4/21.
//  Copyright © 2021 边俊林. All rights reserved.
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
class Solution {
    struct Node {
        pair<int, int> *num = NULL;
        pair<Node *, Node *> *nds = NULL;
        int val;

        Node(pair<int, int> * num, pair<Node *, Node*> *nds) : num(num), nds(nds) {
            this->val = num != NULL ? min(num->first, num->second) : min(nds->first->val, nds->second->val);
        }
    };

    vector<Node *> merge(vector<Node *> nodes) {
        if (nodes.size() <= 1) return nodes;
        sort(nodes.begin(), nodes.end(), [](auto& lhs, auto& rhs) { return lhs->val < rhs->val; } );
        vector<Node *> newNodes;
        for (int i = 0; i < nodes.size() / 2; ++i) {
            auto pir = new pair<Node *, Node*>(nodes[i], nodes[nodes.size()-1-i]);
            newNodes.push_back(new Node(NULL, pir));
        }
        return merge(newNodes);
    }

    string toString(vector<Node *> nodes) {
        string str = "(";
        for (int i = 0; i < nodes.size(); ++i) {
            if (i != 0) str += ",";
            auto& node = nodes[i];
            if (node->num) {
                str += to_string(node->num->first) + "," + to_string(node->num->second);
            } else {
                str += toString({node->nds->first});
                str += ",";
                str += toString({node->nds->second});
            }
        }
        return str + ")";
    }

public:
    string findContestMatch(int n) {
        vector<Node *> nodes;
        for (int i = 1; i <= n / 2; ++i) {
            auto pir = new pair<int, int>(i, n-i+1);
            nodes.push_back(new Node(pir, NULL));
        }
        auto res = merge(nodes);
        return toString(res);
    }
};

int main() {
    Solution sol = Solution();
    int mask = 1;
    for (int i = 0; i < 4; ++i) {
        mask <<= 1;
        string res = sol.findContestMatch(mask);
        cout << res << endl;
    }
//    cout << sol.findContestMatch(4) << endl;
    return 0;
}
