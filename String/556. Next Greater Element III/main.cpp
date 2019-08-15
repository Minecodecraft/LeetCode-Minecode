//
//  main.cpp
//  556. Next Greater Element III
//
//  Created by 边俊林 on 2019/8/15.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/next-greater-element-iii/
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
    int nextGreaterElement(int n) {
        string nstr = to_string(n);
        int len = nstr.length();
        int p = len-1;
        while (p > 0) {
            if (nstr[p] > nstr[p-1]) break;
            --p;
        }
        if (p == 0)
            return -1;

        int minidx = p;
        char minnch = nstr[p];
        for (int i = p; i < len; ++i) {
            if (nstr[i] > nstr[p-1] && nstr[i] < minnch) {
                minnch = nstr[i];
                minidx = i;
            }
        }
        swap(nstr[p-1], nstr[minidx]);
        sort(nstr.begin() + p, nstr.end());
        long lres = stol(nstr);
        if (lres > INT_MAX)
            return -1;
        return (int)lres;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 12;
//    int n = 21;
//    int n = 123456897;
    int n = 1999999999;
    auto res = sol.nextGreaterElement(n);
    cout << res << endl;
    return 0;
}
