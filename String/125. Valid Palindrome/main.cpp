//
//  main.cpp
//  125. Valid Palindrome
//
//  Created by 边俊林 on 2019/8/1.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/valid-palindrome/
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
    bool isPalindrome(string s) {
        auto len = s.length();
        int l = 0, r = len-1;
        while (l <= r) {
            while (l < len && !isAlphanum(s[l])) ++l;
            while (r >= 0 && !isAlphanum(s[r])) --r;
            if (l < len && r >= 0) {

                if (tolower(s[l]) != tolower(s[r]))
                    return false;
                ++l; --r;
            }
        }
        return l >= r;
    }

private:
    bool isAlphanum(char ch) {
        return isalpha(ch) || isdigit(ch);
    }
};

int main() {
    Solution sol = Solution();
//    string s = "A man, a plan, a canal: Panama";
//    string s = "race a car";
    string s = "0P";
    auto res = sol.isPalindrome(s);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
