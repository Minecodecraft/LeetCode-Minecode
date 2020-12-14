//
//  main.cpp
//  524. Longest Word in Dictionary through Deleting
//
//  Created by Jaylen Bian on 12/14/20.
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
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        vector<bool> vis (26, false);
        for (char ch: s)
            vis[ch - 'a'] = true;

        for (int i = 0; i < d.size(); ++i) {
            int p = 0, j = 0;
            if (res.length() > d[i].length())
                continue;
            for (j = 0; j < d[i].length(); ++j) {
                if (!vis[d[i][j]-'a']) break;
                while (p < s.length() && s[p] != d[i][j])
                    ++p;
                if (p++ >= s.length())
                    break;
            }
            if (j == d[i].length())
                res = res.length() == d[i].length() ? min(res, d[i]) : d[i];
        }
        return res;
    }
};

int main() {

    return 0;
}
