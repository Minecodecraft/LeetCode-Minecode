//
//  main.cpp
//  49. Group Anagrams
//
//  Created by 边俊林 on 2019/7/25.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/group-anagrams/
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<unsigned long long, vector<string>> mp;
        vector<int> alpha = vector<int>(26, 0);

        for (int i = 0; i < strs.size(); ++i) {
            fill(alpha.begin(), alpha.end(), 0);
            for (int j = 0; j < strs[i].length(); ++j)
                alpha[strs[i][j] - 'a']++;
            int hash = getHash(alpha);
            if (mp.find(hash) == mp.end())
                mp[hash] = {strs[i]};
            else
                mp[hash].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); ++it)
            res.push_back(it->second);
        return res;
    }

private:
    const int SEED = 123;
    unsigned long long getHash(vector<int>& alpha) {
        unsigned long long res = 0;
        for (int i = 0; i < alpha.size(); ++i) {
            res = res * SEED + alpha[i];
        }
        return res;
    }
};

void printVector(vector<string> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c", it==v.begin() ? '\0' : ' ');
        cout << *it << endl;
    }
    printf("]\n");
}
void printVectors(vector<vector<string>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    auto res = sol.groupAnagrams(strs);
    printVectors(res);
    return 0;
}
