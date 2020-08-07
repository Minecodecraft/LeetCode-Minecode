//
//  main.cpp
//  247. Strobogrammatic Number II
//
//  Created by Jaylen Bian on 8/7/20.
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

    unordered_map<char, char> stro = {
        {'0', '0'}, {'1', '1'},
        {'6', '9'}, {'9', '6'},
        {'8', '8'}
    };
    int n;

    void recur(int last,  vector<string>& res, string pre, string suf) {
        if (last <= 0) {
            res.emplace_back(pre+suf);
            return;
        }
        for (auto it = stro.begin(); it != stro.end(); ++it) {
            if (last == n && n != 1 && it->first == '0') continue;
            if (last == 1 && it->first == it->second) {
                recur(last-1, res, pre+it->first, suf);
            } else if (last > 1) {
                recur(last-2, res, pre+it->first, it->second + suf);
            }
        }
    }

public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> res;
        this->n = n;
        recur(n, res, "", "");
        return res;
    }
};

int main() {

    return 0;
}
