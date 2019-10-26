//
//  main.cpp
//  242. Valid Anagram
//
//  Created by 边俊林 on 2019/10/26.
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
    bool isAnagram(string s, string t) {
        vector<int> cnt (26), cnt2 (26);
        for (char& ch: s) cnt[ch-'a']++;
        for (char& ch: t) cnt2[ch-'a']++;
        return cnt == cnt2;
    }
};

int main() {

    return 0;
}
