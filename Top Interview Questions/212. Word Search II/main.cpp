//
//  main.cpp
//  212. Word Search II
//
//  Created by 边俊林 on 2019/10/25.
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
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node *root = makeTrie(words);
        vector<string> res;
        int n = board.size(), m = n ? board[0].size() : 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                findTrie(root, i, j, board, words, res);
            }
        }
        return res;
    }

private:
    struct Node {
        bool isWord = false;
        int idx = 0;
        vector<Node*> nodes = vector<Node*>(26, NULL);
    };
    int dir[5] = {0, 1, 0, -1, 0};

    Node* makeTrie(vector<string>& word) {
        Node* root = new Node();
        for (int idx = 0; idx < word.size(); ++idx) {
            Node* node = root;
            string str = word[idx];
            int p = 0;
            while (p < str.length()) {
                if (node->nodes[str[p] - 'a'] == NULL)
                    node->nodes[str[p] - 'a'] = new Node();
                node = node->nodes[str[p] - 'a'];
                ++p;
            }
            node->isWord = true;
            node->idx = idx;
        }
        return root;
    }

    void findTrie(Node* root, int x, int y, vector<vector<char>>& board, vector<string>& words, vector<string>& res) {
        if (board[x][y] == '#') return;
        char curch = board[x][y];
        if (root->nodes[curch-'a'] == NULL)
            return;
        if (root->nodes[curch-'a']->isWord) {
            res.push_back(words[root->nodes[curch-'a']->idx]);
            root->nodes[curch-'a']->isWord = false;
        }

        board[x][y] = '#';
        for (int i = 0; i < 4; ++i) {
            int tx = x + dir[i];
            int ty = y + dir[i+1];
            if (tx>=0 && tx<board.size() && ty>=0 && ty<board[0].size())
                findTrie(root->nodes[curch-'a'], tx, ty, board, words, res);
        }
        board[x][y] = curch;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> strs = {
//        "oaan", "etae", "ihkr", "iflv"
        "bbaaba",
        "bbabaa",
        "bbbbbb",
        "aaabaa",
        "abaabb"
    };
    vector<vector<char>> mat;
    for (auto& str: strs) {
        mat.push_back(vector<char>(str.begin(), str.end()));
    }
    vector<string> words = {
//        "oath","pea","eat","rain"
        "abbbababaa"
    };
    auto res = sol.findWords(mat, words);
    for (auto& str: res) {
        cout << str << endl;
    }
    return 0;
}
