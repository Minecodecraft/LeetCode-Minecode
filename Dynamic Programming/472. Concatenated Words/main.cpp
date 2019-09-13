//
//  main.cpp
//  472. Concatenated Words
//
//  Created by 边俊林 on 2019/9/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/concatenated-words/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Node *root = new Node();
        for (auto &str: words) {
            Node *pnode = root;
            for (int i = 0; i < str.length(); ++i) {
                int key = str[i] - 'a';
                if (pnode->nodes[key] == NULL)
                    pnode->nodes[key] = new Node();
                pnode = pnode->nodes[key];
            }
            pnode->isWord = true;
        }

        vector<string> res;
        for (auto &str: words) {
            if (isConcatenated(str, 0, root))
                res.push_back(str);
        }
        return res;
    }

private:
    struct Node {
        vector<Node *> nodes = vector<Node *>(26);
        bool isWord = false;
    };

    bool isConcatenated(string str, int cnt, Node* root) {
        if (str.empty()) return false;
        if (root == NULL) return false;
        int idx = 0;
        Node *pnode = root;
        while (idx < str.length()) {
            int key = str[idx] - 'a';
            if (pnode->nodes[key] == NULL) return false;
            if (pnode->nodes[key]->isWord) {
                if (isConcatenated(str.substr(idx+1), cnt+1, root))
                    return true;
            }
            ++idx;
            pnode = pnode->nodes[key];
        }
        return idx == str.length() && pnode != NULL && pnode->isWord == true && cnt+1 >= 2;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> words = {
//        "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"
        "cat", "dog", "cow"
    };
    vector<string> res = sol.findAllConcatenatedWordsInADict(words);
    for (auto str: res) {
        cout << str << endl;
    }
    return 0;
}
