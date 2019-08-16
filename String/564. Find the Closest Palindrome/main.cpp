//
//  main.cpp
//  564. Find the Closest Palindrome
//
//  Created by 边俊林 on 2019/8/16.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/find-the-closest-palindrome/
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
    string nearestPalindromic(string n) {
        if (n == "0") return "1";

        vector<string> palins;

        palins.push_back(toDownNine(n));
        palins.push_back("0");
        palins.push_back(toPali(n));
        palins.push_back(toPali(toUpper(n)));
        palins.push_back(toPali(toLower(n)));

        string minStr;
        long long minNum;
        long long minDif = LONG_LONG_MAX;
        long long num = stoll(n);
        for (int i = 0; i < palins.size(); ++i) {
            if (palins[i] == n) continue;
            long long thisnum = stoll(palins[i]);
            if (abs(num - thisnum) == minDif) {
                if (thisnum < minNum) {
                    minStr = palins[i];
                    minNum = thisnum;
                }
            } else if (abs(num - thisnum) < minDif) {
                minDif = abs(num - thisnum);
                minStr = palins[i];
                minNum = thisnum;
            }
        }
        return minStr;
    }

private:
    string toUpper(const string& s) {
        int len = s.length();
        string prefix = s.substr(0, (len+1) >> 1);
        long long prenum = stoll(prefix);
        prenum = (prenum+1) * pow(10, (int)len >> 1);
        return to_string(prenum);
    }

    string toLower(const string& s) {
        if (s[0] == '1' && s.length() == 2) return "9";
        int len = s.length();
        string prefix = s.substr(0, (len+1) >> 1);
        long long prenum = stoll(prefix);
        prenum = (prenum-1) * pow(10, (int)len >> 1);
        return to_string(prenum);
    }

    string toPali(const string& s) {
        int len = s.length();
        string prefix = s.substr(0, (len+1) >> 1);
        string suffix = s.substr(0, len >> 1);
        reverse(suffix.begin(), suffix.end());
        return prefix + suffix;
    }

    string toDownNine(const string& s) {
        if (s.length() <= 1) return "0";
        return string((int)s.length()-1, '9');
    }

    bool isPalindrome(const string& s) {
        int l = 0, r = s.length()-1;
        while (l <= r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol = Solution();
    string n = "10";
    auto res = sol.nearestPalindromic(n);
    cout << res << endl;
    vector<string> strs = {
        "123", "1234", "1", "1221", "100000", "807045053224792883",
        "11", "8", "99", "10", "1283"
    };
    for (int i = 0; i < strs.size(); ++i) {
        auto res = sol.nearestPalindromic(strs[i]);
        cout << res << endl;
    }
//    string n = "123";
//    string n = "1234";
//    string n = "1";
//    string n = "1221";
//    string n = "100000";
//    string n = "807045053224792883";
    return 0;
}
