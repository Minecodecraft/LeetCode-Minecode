//
//  main.cpp
//  767. Reorganize String
//
//  Created by 边俊林 on 2019/10/11.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
\* ------------------------------------------------------ */

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
    string reorganizeString(string S) {
        if (S.empty()) return S;
        unordered_map<char, int> cnt;
        for (char& ch: S) cnt[ch]++;

        auto cmp = [](pair<char, int>& a, pair<char, int>& b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        };
        using pir = pair<char, int>;
        priority_queue<pir, vector<pir>, decltype(cmp)> pq (cmp);
        for (auto& kv: cnt) pq.emplace(kv.first, kv.second);

        string res = "";
        while (pq.size() > 1) {
            pir p1 = pq.top(); pq.pop();
            pir p2 = pq.top(); pq.pop();
            if (res.length() && res.back() == p1.first) return "";
            res += p1.first;
            res += p2.first;
            p1.second--; p2.second--;
            if (p1.second) pq.emplace(p1);
            if (p2.second) pq.emplace(p2);
        }
        if (pq.size()) {
            if (pq.top().second > 1) return "";
            return res.length() && pq.top().first == res.back() ? "" : res+pq.top().first;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "aab";
//    string s = "aaab";
//    string s = "vvvlo";
//    string s = "bfrbs";
    string res = sol.reorganizeString(s);
    cout << res << endl;
    return 0;
}
