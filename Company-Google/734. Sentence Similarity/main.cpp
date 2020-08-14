//
//  main.cpp
//  734. Sentence Similarity
//
//  Created by Jaylen Bian on 8/13/20.
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
public:
    bool areSentencesSimilar(vector<string>& ws1, vector<string>& ws2, vector<vector<string>>& prs) {
        if (ws1.size() != ws2.size())
            return false;
        unordered_map<string, unordered_set<string>> match;
        for (auto& pr: prs) {
            match[pr[0]].insert(pr[1]);
            match[pr[1]].insert(pr[0]);
        }
        for (int i = 0; i < ws1.size(); ++i) {
            if (ws1[i] != ws2[i] && !match[ws1[i]].count(ws2[i]) && !match[ws2[i]].count(ws1[i]))
                return false;
        }
        return true;
    }
};

int main() {

    return 0;
}
