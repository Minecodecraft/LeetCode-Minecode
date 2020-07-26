//
//  main.cpp
//  159. Longest Substring with At Most Two Distinct Characters
//
//  Created by Jaylen Bian on 7/26/20.
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> mp;
        int beg = 0;
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            mp[s[i]]++;
            while (mp.size() > 2) {
                char ch = s[beg++];
                mp[ch] == 1 ? mp.erase(ch) : mp[ch]--;
            }
            res = max(res, i-beg+1);
        }
        return res;
    }
};

int main() {

    return 0;
}
