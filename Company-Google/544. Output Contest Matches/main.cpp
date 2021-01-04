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
// Solution 1: Very ugly and complex solution
/*
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
 */

// Solution 2: Simulation, simple and concise
// Time Complexity: O(NlogN), Space Complexity: O(N)
/*
class Solution {
public:
    string findContestMatch(int n) {
        vector<string> strs (n);
        for (int i = 1; i <= n; ++i)
            strs[i-1] = to_string(i);

        for (; n > 1; n >>= 1)
            for (int i = 0; i < n / 2; ++i)
                strs[i] = "(" + strs[i] + "," + strs[n - i - 1] + ")";
        return strs[0];
    }
};
 */

// Solution 3: Use deqeue to simplify the code of solution 1
class Solution {
    string makePair(deque<string> q) {
        if (q.size() > 1) {
            deque<string> tmp;
            int n = q.size();
            for (int i = 0; i < n / 2; ++i) {
                string str = "(" + q.front() + "," + q.back() + ")";
                tmp.push_back(str);
                q.pop_front();
                q.pop_back();
            }
            return makePair(tmp);
        }
        return q.front();
    }

public:
    string findContestMatch(int n) {
        deque<string> q;
        for (int i = 1; i <= n; ++i)
            q.push_back(to_string(i));
        return makePair(q);
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
