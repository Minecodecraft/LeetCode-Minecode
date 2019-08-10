//
//  main.cpp
//  336. Palindrome Pairs
//
//  Created by 边俊林 on 2019/8/9.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/palindrome-pairs/
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
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
        unordered_map<string, int> mp;
        vector<vector<int>> res;

        for (int i = 0; i < words.size(); ++i) {
            string tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            mp[tmp] = i;
        }

        if (mp.find("") != mp.end()) {
            for (int i = 0; i < n; ++i) {
                if (words[i] == "") continue;
                if (isPalinadrome(words[i]))
                    res.push_back({mp[""], i});
            }
        }

        for (int i = 0; i < n; ++i) {
            auto str = words[i];
            for (int j = 0; j < str.length(); ++j) {
                string lstr = str.substr(0, j);
                string rstr = str.substr(j, str.length()-j);

                if (mp.find(lstr) != mp.end() && mp[lstr] != i && isPalinadrome(rstr))
                    res.push_back({i, mp[lstr]});
                if (mp.find(rstr) != mp.end() && mp[rstr] != i && isPalinadrome(lstr))
                    res.push_back({mp[rstr], i});
            }
        }

        return res;
    }

private:
    bool isPalinadrome(string str) {
        // manacher
        int l = 0, r = str.length()-1;
        while (l <= r) {
            if (str[l++] != str[r--])
                return false;
        }
        return true;
    }
};

// Tool Function List
void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}
void printVectors(vector<vector<int>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    vector<string> words = {
        "abcd","dcba","lls","s","sssll"
    };
    auto res = sol.palindromePairs(words);
    printVectors(res);
    return 0;
}
