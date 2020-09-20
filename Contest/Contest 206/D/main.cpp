//
//  main.cpp
//  D
//
//  Created by Jaylen Bian on 9/20/20.
//  Copyright © 2020 Jaylen Bian. All rights reserved.
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
    bool isTransformable(string s, string t) {
        int n = s.length();
        vector<vector<int>> pos (10);
        vector<int> used (10, 0);
        for (int i = 0; i < n; ++i) {
            int idx = s[i] - '0';
            pos[idx].push_back(i);
        }
        for (int i = 0; i < n; ++i) {
            int idx = t[i] - '0';
            if (used[idx] >= pos[idx].size())
                return false;
            for (int j = 0; j < idx; ++j) {
                if (used[j] < pos[j].size() && pos[j][used[j]] < pos[idx][used[idx]])
                    return false;
            }
            ++used[idx];
        }
        return true;
    }
};


int main() {

    return 0;
}
