//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/12/22.
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
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        vector<int> cnt (26, 0);
        int wcnt = 0, res = 0;
        unordered_map<string, int> scnt;

        for (int i = 0; i < minSize; ++i)
            if (cnt[s[i]-'a']++ == 0) wcnt++;
        for (int i = minSize; i <= s.length(); ++i) {
            if (wcnt <= maxLetters) {
                scnt[s.substr(i-minSize, minSize)]++;
            }
            if (i == s.length()) break;
            if (--cnt[s[i-minSize]-'a'] == 0) wcnt--;
            if (cnt[s[i]-'a']++ == 0) wcnt++;
        }
        for (auto& kv: scnt) res = max(res, kv.second);
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "aababcaab";
    int a = 2, b = 3, c = 4;
    int res = sol.maxFreq(s, a, b, c);
    cout << res << endl;
    return 0;
}
