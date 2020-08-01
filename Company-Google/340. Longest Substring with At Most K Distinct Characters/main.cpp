//
//  main.cpp
//  340. Longest Substring with At Most K Distinct Characters
//
//  Created by Jaylen Bian on 8/1/20.
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
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> cnt (256, 0);
        int l = 0, r = 0;
        int chs = 0, res = 0;
        for (r = 0; r < s.length(); ++r) {
            if (cnt[s[r]]++ == 0) {
                ++chs;
            }
            while (chs > k) {
                if (--cnt[s[l++]] == 0)
                    --chs;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};

int main() {

    return 0;
}
