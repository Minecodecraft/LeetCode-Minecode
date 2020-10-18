//
//  main.cpp
//  1055. Shortest Way to Form String
//
//  Created by Jaylen Bian on 10/18/20.
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
// Solution 1: Greedy
/*
class Solution {
public:
    int shortestWay(string source, string target) {
        int n = source.length();
        vector<bool> found (26, false);
        for (char ch: source)
            found[ch-'a'] = true;
        int p = 0;
        for (char ch: target) {
            if (!found[ch-'a'])
                return -1;
            while (source[p % n] != ch)
                ++p;
            ++p;
        }
        return (p + n - 1) / n;
    }
};
 */

// Solution 2: Optimized by binary search
class Solution {
public:
    int shortestWay(string source, string target) {
        vector<vector<int>> poss = vector<vector<int>> (26);
        for (int i = 0; i < source.size(); ++i)
            poss[source[i]-'a'].push_back(i);

        int res = 1;
        for (int i = 0, j = -1; i < target.size();) {
            auto& pos = poss[target[i]-'a'];
            if (pos.empty())
                return -1;
            auto it = upper_bound(pos.begin(), pos.end(), j);
            if (it == pos.end()) {
                ++res;
                j = -1;
            } else {
                j = *it;
                ++i;
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "abc";
    string t = "abcbc";
    int res = sol.shortestWay(s, t);
    cout << res << endl;
    return 0;
}
