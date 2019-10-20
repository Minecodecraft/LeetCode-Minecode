//
//  main.cpp
//  131. Palindrome Partitioning
//
//  Created by 边俊林 on 2019/10/20.
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
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};
        vector<vector<string>> res;
        vector<string> path;
        recursive(s, 0, path, res);
        return res;
    }

private:
    void recursive(string s, int idx, vector<string>& path, vector<vector<string>>& res) {
        if (idx == s.length()) {
            res.push_back(path);
            return;
        }

        for (int i = idx; i < s.length(); ++i) {
            if (isPalin(s, idx, i)) {
                path.push_back(s.substr(idx, i-idx+1));
                recursive(s, i+1, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalin(const string& s, int beg, int end) {
        while (beg <= end) {
            if (s[beg] != s[end]) return false;
            beg++; end--;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    string s = "aab";
    auto res = sol.partition(s);
    for (auto& strs: res) {
        for (auto& str: strs) {
            cout << str << ",";
        }
        cout << endl;
    }
    return 0;
}
