//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2020/3/7.
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
    string sortString(string s) {
        vector<int> cnt(26, 0);
        for (char& ch: s)
            cnt[ch-'a']++;
        string res = "";
        int tot = s.length();
        while (tot) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i] > 0) {
                    tot--;
                    cnt[i]--;
                    res += i + 'a';
                }
            }
            for (int i = 25; i >= 0; --i) {
                if (cnt[i] > 0) {
                    tot--;
                    cnt[i]--;
                    res += i + 'a';
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    string s = "rat";
    string res = sol.sortString(s);
    cout << res << endl;
    return 0;
}
