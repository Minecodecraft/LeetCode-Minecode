//
//  main.cpp
//  520. Detect Capital
//
//  Created by 边俊林 on 2019/8/12.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/detect-capital/
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
    bool detectCapitalUse(string word) {
        bool hasUpper, hasLowwer;
        hasUpper = hasLowwer = false;
        for (int i = 0; i < word.size(); ++i) {
            char& ch = word[i];
            if (!isalpha(ch))
                return false;
            if (isupper(ch)) {
                hasUpper = true;
            }
            if (islower(ch)) {
                hasLowwer = true;
            }
        }
        if (hasUpper + hasLowwer == 1)
            return true;
        if (word.size() >= 1 && isupper(word[0])) {
            for (int i = 1; i < word.size(); ++i)
                if (isupper(word[i]))
                    return false;
            return true;
        }
        return false;
    }
};

int main() {
    Solution sol = Solution();
//    string word = "USA";
//    string word = "FlagG";
//    string word = "Google";
//    string word = "leetcode";
    string word = "ffffffffffffF";
    bool res = sol.detectCapitalUse(word);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
