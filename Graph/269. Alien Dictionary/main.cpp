//
//  main.cpp
//  269. Alien Dictionary
//
//  Created by 边俊林 on 2019/12/12.
//  Copyright © 2019 边俊林. All rights reserved.
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
    string alienOrder(vector<string>& words) {
        unordered_map<char,  unordered_set<char>> mp;
        int wcnt = words.size();

        unordered_set<char> chs;
        for (int i = 0; i < wcnt; ++i)
            for (int j = 0; j < words[i].length(); ++j)
                chs.insert(words[i][j]);

        for (int i = 0; i < wcnt-1; ++i)
            compareAndConn(words[i], words[i+1], mp);

        vector<char> path;
        vector<int> color (26, 0);
        for (int i = 0; i < 26; ++i) {
            if (chs.count('a'+i) && !topoSort(path, color, mp, 'a'+i, chs)) return "";
        }
        string resstr = string(path.rbegin(), path.rend());
        for (char ch: chs)
            resstr.push_back(ch);
        return resstr;
    }

private:
    bool topoSort(vector<char>& path, vector<int>& color, unordered_map<char,  unordered_set<char>>& mp, char u, unordered_set<char>& chs) {
        if (color[u-'a'] != 0) return color[u-'a'] == 2;

        color[u-'a'] = 1;
        for (auto it = mp[u].begin(); it != mp[u].end(); ++it)
            if (!topoSort(path, color, mp, *it, chs)) return false;
        color[u-'a'] = 2;
        path.push_back(u);
        chs.erase(u);
        return true;
    }

    void compareAndConn(string& s1, string& s2, unordered_map<char,  unordered_set<char>>& mp) {
        int p1 = 0, p2 = 0;
        while (p1 < s1.length() && p2 < s2.length()) {
            if (s1[p1] != s2[p2]) {
                mp[s1[p1]].insert(s2[p2]);
                break;
            }
            ++p1, ++p2;
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<string> ws = {
        "wrt",
        "wrf",
        "er",
        "ett",
        "rftt"
    };
    string res = sol.alienOrder(ws);
    cout << res << endl;
    return 0;
}
