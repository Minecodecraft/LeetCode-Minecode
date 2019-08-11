//
//  main.cpp
//  387. First Unique Character in a String
//
//  Created by 边俊林 on 2019/8/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/first-unique-character-in-a-string/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); ++i) {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = 1;
            else
                mp[s[i]] += 1;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (mp[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main() {
    Solution sol = Solution();
    string s = "leetcode";
    int res = sol.firstUniqChar(s);
    cout << res << endl;
    return 0;
}
