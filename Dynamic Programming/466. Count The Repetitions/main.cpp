//
//  main.cpp
//  466. Count The Repetitions
//
//  Created by 边俊林 on 2019/9/10.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/count-the-repetitions/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
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
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<int> onetimelen (len2, 0);
        for (int i = 0; i < len2; ++i) {
            int p = i;
            for (int j = 0; j < len1; ++j)
                if (s1[j] == s2[p % len2])
                    ++p;
            if (p == i) return 0;
            onetimelen[i] = p-i;
        }
        int wordcnt = 0;
        for (int i = 0; i < n1; ++i) {
            wordcnt += onetimelen[wordcnt % len2];
        }
        return wordcnt / (len2 * n2);
    }
};

int main() {
    Solution sol = Solution();
    string s1 = "aaa";
    string s2 = "aaaaa";
    int res = sol.getMaxRepetitions(s1, 20, s2, 1);
    cout << res << endl;
    return 0;
}
