//
//  main.cpp
//  833. Find And Replace in String
//
//  Created by Jaylen Bian on 10/19/20.
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
    bool check(string& s, string& source, int p) {
        for (char ch: source)
            if (p >= s.length() || s[p++] != ch)
                return false;
        return true;
    }

public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string res = "";
        int p = 0, pidx = 0;

        vector<pair<int, pair<string, string>>> nodes;
        for (int i = 0; i < indexes.size(); ++i) {
            nodes.push_back({indexes[i], {sources[i], targets[i]}});
        }
        sort(nodes.begin(), nodes.end());

        while (p < s.length()) {
            if (pidx < nodes.size() && nodes[pidx].first == p) {
                if (check(s, nodes[pidx].second.first, p)) {
                    p += nodes[pidx].second.first.length();
                    res += nodes[pidx++].second.second;
                } else {
                    res += s[p++];
                    pidx++;
                }
            } else {
                res += s[p++];
            }
        }
        return res;
    }
};

// Test Case
/*
 "abcd"
 [0, 2]
 ["a", "cd"]
 ["eee", "ffff"]
 "abcd"
 [0, 2]
 ["ab", "ec"]
 ["eee", "ffff"]
 "vmokgggqzp"
 [3,5,1]
 ["kg","ggq","mo"]
 ["s","so","bfr"]
 */

int main() {

    return 0;
}
