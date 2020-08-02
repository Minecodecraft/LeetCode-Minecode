//
//  main.cpp
//  642. Design Search Autocomplete System
//
//  Created by Jaylen Bian on 7/29/20.
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
struct Node {
    vector<Node* > nodes = vector<Node*> (27, NULL);
    string str = "";
    int cnt = 0;
};

class AutocompleteSystem {
private:
    Node* root = new Node();
    string curr = "";
    Node* pCurr = root;

    Node* Add(string str, int times) {
        Node* pNode = root;
        string pre = "";
        for (int i = 0; i < str.length(); ++i) {
            pNode = AddChar(str[i], pNode, pre);
            pre += str[i];
        }
        pNode->cnt += times;
        return pNode;
    }

    Node* AddChar(char ch, Node* pNode, string str) {
        int idx = ch == ' ' ? 26 : ch - 'a';
        if (pNode->nodes[idx] == NULL)
            pNode->nodes[idx] = new Node();
        Node* nxt = pNode->nodes[idx];
        nxt->str = str + ch;
        return nxt;
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        for (int i = 0; i < sentences.size(); ++i) {
            Add(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            pCurr->cnt++;
            pCurr = root;
            curr = "";
            return {};
        }

        pCurr = AddChar(c, pCurr, curr);
        curr += c;

        vector<pair<string, int>> match;
        stack<Node*> st;
        st.emplace(pCurr);
        while (st.size()) {
            auto node = st.top(); st.pop();
            if (node->cnt) {
                match.push_back({node->str, node->cnt});
            }
            for (int i = 0; i < 27; ++i) {
                if (node->nodes[i] != NULL) {
                    st.emplace(node->nodes[i]);
                }
            }
        }
        sort(match.begin(), match.end(), [](pair<string, int>& a, pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        });
        vector<string> res;
        for (int i = 0; i < min(3, (int)match.size()); ++i) {
            res.push_back(match[i].first);
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

int main() {
    vector<string> sarr = {
        "i love you","island","iroman","i love leetcode"
    };
    vector<int> tarr = {
        5,3,2,2
    };
    AutocompleteSystem sol = AutocompleteSystem(sarr, tarr);
    vector<char> chs = {
        'i', ' ', 'a', '#'
    };
    for (auto ch: chs) {
        auto res = sol.input(ch);
        for_each(res.begin(), res.end(), [](auto str) { cout << str << endl; });
        cout << "-------------" << endl;
    }

    return 0;
}
