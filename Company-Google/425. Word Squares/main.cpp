//
//  main.cpp
//  425. Word Squares
//
//  Created by Jaylen Bian on 12/18/20.
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
class Solution {
    typedef struct Node {
        vector<Node *> nodes;
        vector<string> strs;

        Node() {
            this->nodes = vector<Node *>(26);
        };
    } Node;

    Node* root = new Node();
public:
    vector<vector<string>> wordSquares(vector<string>& strs) {
        if (strs.empty() || strs[0].length() == 0)
            return {};
        // build trie
        for (string str: strs) {
            Node* node = root;
            for (char ch: str) {
                int idx = ch-'a';
                if (node->nodes[idx] == NULL)
                    node->nodes[idx] = new Node();
                node->nodes[idx]->strs.push_back(str);
                node = node->nodes[idx];
            }
        }

        // find
        vector<vector<string>> res;
        vector<string> arr;
        for (string str: strs) {
            arr.push_back(str);
            dfs(res, arr, strs[0].length());
            arr.pop_back();
        }
        return res;
    }

    void dfs(vector<vector<string>>& res, vector<string>& arr, int len) {
        if (arr.size() == len) {
            res.push_back(arr);
            return;
        }
        vector<string> matchs = findNode(arr, arr.size());
        for (string& str: matchs) {
            arr.push_back(str);
            dfs(res, arr, len);
            arr.pop_back();
        }
    }

    vector<string> findNode(vector<string>& arr, int idx) {
        Node* curr = root;
        for (string& str: arr) {
            char ch = str[idx];
            if (curr->nodes[ch-'a'] != NULL)
                curr = curr->nodes[ch-'a'];
            else
                return {};
        }
        return curr->strs;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> strs = {
        "area","lead","wall","lady","ball"
    };
    auto res = sol.wordSquares(strs);
    cout << "result" << endl;
    for (auto subele: res) {
        for_each(subele.begin(), subele.end(), [] (string ele) { cout << ele << endl;});
        cout << endl;
    }
    return 0;
}
