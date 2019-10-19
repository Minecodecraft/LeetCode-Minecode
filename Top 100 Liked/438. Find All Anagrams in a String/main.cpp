//
//  main.cpp
//  438. Find All Anagrams in a String
//
//  Created by 边俊林 on 2019/10/19.
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
    vector<int> findAnagrams(string s, string p) {
        int la = s.length(), lb = p.length();
        if (la < lb || lb == 0) return {};
        vector<int> res;
        unordered_map<char, int> pcnt;
        for (int i = 0; i < lb; ++i)
            pcnt[p[i]]++;
        unordered_map<char, int> cnt;
        for (int i = 0; i < lb-1; ++i)
            cnt[s[i]]++;
        for (int i = lb-1; i < la; ++i) {
            cnt[s[i]]++;
            if (check(cnt, pcnt))
                res.push_back(i-lb+1);
            cnt[s[i-lb+1]]--;
        }
        return res;
    }

private:
    bool check(unordered_map<char, int>& cnt, unordered_map<char, int>& pcnt) {
        for (auto& kv: pcnt) {
            if (cnt.count(kv.first) == 0 || cnt[kv.first] != kv.second)
                return false;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "cbaebabacd";
//    string p = "abc";
    string s = "abab";
    string p = "ab";
    auto res = sol.findAnagrams(s, p);
    cout << res.size() << endl;
    return 0;
}
