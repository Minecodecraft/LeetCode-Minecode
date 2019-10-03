//
//  main.cpp
//  331. Verify Preorder Serialization of a Binary Tree
//
//  Created by 边俊林 on 2019/10/3.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
\* ------------------------------------------------------ */

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
// Solution 1: Recursivce, 563ms, beats 5% 🤢
/*
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return true;
        int idx = 0;
        vector<string> strs;
        int l = 0, r = l;
        while (l < preorder.size()) {
            r = l;
            if (preorder[r] == ',')
                ++r;
            else if (preorder[r] == '#')
                strs.push_back("#"), ++r;
            else {
                while (r < preorder.length() && isdigit(preorder[r])) ++r;
                strs.push_back(preorder.substr(l, r-l));
            }
            l = r+1;
        }
        return isValid(strs, idx) && idx == strs.size();
    }

private:
    bool isValid(vector<string> strs, int& idx) {
        if (strs.empty() || idx >= strs.size()) return false;
        if (strs[idx] == "#") {
            idx++;
            return true;
        } else {
            idx++;
            return isValid(strs, idx) &&
                    isValid(strs, idx);
        }
        return false;
    }
};
 */

// Solution 2: O(n) Time Complexity, O(1) Space Complexity
// When adding a node, capacity -1, when adding a non-leaf node, capacity +2
// Initially the capacity will be 1 for the root.
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.empty()) return false;
        preorder += ",";
        int capacity = 1, len = preorder.length();
        for (int i = 0; i < len; ++i) {
            if (preorder[i] != ',') continue;
            capacity--;
            if (capacity < 0) return false;
            if (preorder[i-1] != '#') capacity += 2;
        }
        return capacity == 0;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    string s = "1,#";
//    string s = "9,#,#,1";
    bool res = sol.isValidSerialization(s);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
