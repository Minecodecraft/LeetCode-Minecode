//
//  main.cpp
//  208. Implement Trie (Prefix Tree)
//
//  Created by 边俊林 on 2019/10/17.
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
class Trie {
public:
    struct Node {
        char ch;
        bool isWord = false;
        vector<Node* > nodes = vector<Node* > (26, NULL);

        Node (char ch)
        : ch(ch) { }
    };

    Trie() {
        pRoot = new Node('a');
    }

    void insert(string word) {
        Node* pNode = pRoot;
        for (char& ch: word) {
            if (pNode->nodes[ch-'a'] == NULL)
                pNode->nodes[ch-'a'] = new Node(ch);
            pNode = pNode->nodes[ch-'a'];
        }
        pNode->isWord = true;
    }

    bool search(string word) {
        Node* pNode = pRoot;
        for (char& ch: word) {
            if (pNode->nodes[ch-'a'] == NULL)
                return false;
            pNode = pNode->nodes[ch-'a'];
        }
        return pNode->isWord;
    }

    bool startsWith(string prefix) {
        Node* pNode = pRoot;
        for (char& ch: prefix) {
            if (pNode->nodes[ch-'a'] == NULL)
                return false;
            pNode = pNode->nodes[ch-'a'];
        }
        return true;
    }

private:
    Node* pRoot;
};

int main() {
    Trie trie = Trie();
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;
    return 0;
}
