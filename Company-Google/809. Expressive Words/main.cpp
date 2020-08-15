//
//  main.cpp
//  809. Expressive Words
//
//  Created by Jaylen Bian on 8/15/20.
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
    bool helper(string s, string wd) {
        int p1 = 0, p2 = 0;
        while (p1 < s.length() && p2 < wd.length()) {
            int cnt1 = 1, cnt2 = 1;
            if (s[p1] != wd[p2])
                return false;
            while (p1+1 < s.length() && s[p1] == s[p1+1])
                ++cnt1, ++p1;
            while (p2+1 < wd.length() && wd[p2] == wd[p2+1])
                ++cnt2, ++p2;
            if ((cnt1 != cnt2 && cnt1 < 3) || (cnt1 < cnt2))
                return false;
            ++p1, ++p2;
        }
        return p1 == s.length() && p2 == wd.length();
    }
public:
    int expressiveWords(string s, vector<string>& words) {
        int res = 0;
        for (string& str: words)
            if (helper(s, str)) ++res;
        return res;
    }
};

int main() {

    return 0;
}
