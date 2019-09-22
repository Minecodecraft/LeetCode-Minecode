//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/9/21.
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string res = s;
        for (int i = 0; i < pairs.size(); ++i) {
            int l = min(pairs[i][0], pairs[i][1]);
            int r = max(pairs[i][0], pairs[i][1]);
            if (s[l] > s[r])
                swap(s[l], s[r]);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "dcab";
    string s = "vbjjxgdfnru";
//    string s = "udyyek";
    vector<vector<int>> pirs = {
//        {0, 3}, {1, 2}, {0, 2}
        {8,6},{3,4},{5,2},{5,5},{3,5},{7,10},{6,0},{10,0},{7,1},{4,8},{6,2}
//        {3,3},{3,0},{5,1},{3,1},{3,4},{3,5}
    };
    string res = sol.smallestStringWithSwaps(s, pirs);
    cout << res << endl;
    return 0;
}
