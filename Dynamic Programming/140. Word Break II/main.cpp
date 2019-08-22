//
//  main.cpp
//  140. Word Break II
//
//  Created by 边俊林 on 2019/8/22.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
 \* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
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
// 需要增加cache
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> hasa (wordDict.begin(), wordDict.end());
        return wordBreakCore(s, hasa);
    }

private:
    unordered_map<string, vector<string>> breakMap;

    vector<string> wordBreakCore(string s, const unordered_set<string>& words) {
        if (breakMap.count(s))
            return breakMap[s];

        vector<string> res;
        if (words.count(s))
            res.push_back(s);
        for (int i = 1; i < s.length(); ++i) {
            // 如果取prefix，“判断前面需不需要加空格”比较麻烦
            string suffix = s.substr(i);
            if (words.count(suffix)) {
                vector<string> tmp = parse(suffix, wordBreakCore(s.substr(0, i), words));
                res.insert(res.end(), tmp.begin(), tmp.end());
            }
        }
        breakMap[s] = res;
        return res;
    }

    vector<string> parse(string suffix, vector<string> arr) {
        for (auto& elem : arr) {
            elem += " " + suffix;
        }
        return arr;
    }
};

// Tool Function List
void printVector(vector<string> v) {
    printf("[\n");
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
//    string s = "catsanddog";
//    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
    string s = "pineapplepenapple";
    vector<string> dict = {"apple", "pen", "applepen", "pine", "pineapple"};
//    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
//    vector<string> dict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    auto res = sol.wordBreak(s, dict);
    printVector(res);
    return 0;
}
