//
//  main.cpp
//  737. Sentence Similarity II
//
//  Created by Jaylen Bian on 8/15/20.
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
    unordered_map<string, int> pos;
    vector<int> f;
    int _cnt = 0;

    bool Union(string a, string b) {
        int fa = Find(pos[a]);
        int fb = Find(pos[b]);
        if (fa == fb) return false;
        f[fa] = fb;
        return true;
    }

    int Find(int u) {
        if (f[u] == u) return u;
        return f[u] = Find(f[u]);
    }

    bool Add(string s) {
        if (pos.count(s))
            return false;
        pos[s] = _cnt++;
        return true;
    }

public:
    bool areSentencesSimilarTwo(vector<string>& ws1, vector<string>& ws2, vector<vector<string>>& prs) {
        if (ws1.size() != ws2.size())
            return false;

        // Init UnionFind
        for (string& s: ws1) Add(s);
        for (string& s: ws2) Add(s);
        for (auto& pr: prs)
            Add(pr[0]), Add(pr[1]);
        f = vector<int> (_cnt);
        for (int i = 0; i < _cnt; ++i) f[i] = i;

        // UnionFind
        for (auto& pr: prs)
            Union(pr[0], pr[1]);

        for (int i = 0; i < ws1.size(); ++i) {
            if (ws1[i] != ws2[i] && Find(pos[ws1[i]]) != Find(pos[ws2[i]]))
                return false;
        }
        return true;
    }
};

int main() {

    return 0;
}
