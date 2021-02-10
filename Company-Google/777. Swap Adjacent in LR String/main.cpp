//
//  main.cpp
//  777. Swap Adjacent in LR String
//
//  Created by Jaylen Bian on 2/10/21.
//  Copyright © 2021 边俊林. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <cstdio>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
// Solution 1: O(n), not enough
/*
class Solution {
public:
    bool canTransform(string s1, string s2) {
        int len = s1.length();
        int i, j;
        string str1, str2;
        for (int i = 0; i < len; ++i)
            if (s1[i] != 'X') str1 += s1[i];
        for (int j = 0; j < len; ++j)
            if (s2[j] != 'X') str2 += s2[j];
        if (str1 != str2)
            return false;

        for (i = 0, j = 0; i < len; ++i, ++j) {
            while (i < len && s1[i] != 'L') ++i;
            while (j < len && s2[j] != 'L') ++j;
            if (i < len && j < len && i < j)
                return false;
        }

        for (i = 0, j = 0; i < len; ++i, ++j) {
            while (i < len && s1[i] != 'R') ++i;
            while (j < len && s2[j] != 'R') ++j;
            if (i < len && j < len && i > j)
                return false;
        }

        return true;
    }
};
 */

// Solution 2: Use one loop
class Solution {
public:
    bool canTransform(string s1, string s2) {
        int len = s1.length(), i = 0, j = 0;
        while (i < len && j < len) {
            if (s1[i] == 'X') ++i;
            if (s2[j] == 'X') ++j;

            if (s1[i] != 'X' && s2[j] != 'X') {
                if (s1[i] != s2[j]) return false;
                if (s1[i] == 'L' && i < j) return false;
                if (s1[i] == 'R' && i > j) return false;
                ++i;
                ++j;
            }
        }
        while (i < len)
            if (s1[i++] != 'X') return false;
        while (j < len)
            if (s2[j++] != 'X') return false;
        return true;
    }
};

int main() {
    Solution sol = Solution();
    string s1 = "", s2 = "";
    bool res = sol.canTransform(s1, s2);
    cout << res << endl;
    return 0;
}
