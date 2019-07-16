//
//  main.cpp
//  17. Letter Combinations of a Phone Number
//
//  Created by 边俊林 on 2019/7/16.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/letter-combinations-of-a-phone-number/
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
    vector<string> letterCombinations(string digits) {
        if (digits.size() <= 0) return {};
        vector<string> res;
        string path = "";
        int idx = 0;
        letterCombinationsCore(digits, 0, path, res);
        return res;
    }

private:
    unordered_map<char, string> hash = unordered_map<char, string>({
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxzy"}
    });

    void letterCombinationsCore(string &digits, int idx, string &path, vector<string> &res) {
        if (idx == digits.length()) {
            res.push_back(path);
            return;
        }
        char ch = digits[idx];
        string sign = hash[ch];
        for (auto sym : sign) {
            path.push_back(sym);
            letterCombinationsCore(digits, idx+1, path, res);
            path.pop_back();
        }
    }
};

void printVector(vector<string> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << (it==v.begin() ? '\0' : ' ') << *it << endl;
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
//    string s = "23";
    string s = "";
    auto res = sol.letterCombinations(s);
    printVector(res);
    return 0;
}
