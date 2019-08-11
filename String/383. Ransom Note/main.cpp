//
//  main.cpp
//  383. Ransom Note
//
//  Created by 边俊林 on 2019/8/11.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/ransom-note/
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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for (int i = 0; i < magazine.size(); ++i) {
            if (mp.find(magazine[i]) != mp.end())
                mp[magazine[i]]++;
            else
                mp[magazine[i]] = 1;
        }

        for (int i = 0; i < ransomNote.length(); ++i) {
            if (mp.find(ransomNote[i]) == mp.end() || mp[ransomNote[i]] <= 0)
                return false;
            mp[ransomNote[i]]--;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
//    string ransomNote = "a";
//    string magazine = "b";
//    string ransomNote = "aa";
//    string magazine = "ab";
    string ransomNote = "aa";
    string magazine = "aab";
    bool res = sol.canConstruct(ransomNote, magazine);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
