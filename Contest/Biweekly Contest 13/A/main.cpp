//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2019/11/16.
//  Copyright © 2019 边俊林. All rights reserved.
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
class Solution {
public:
    string encode(int num) {
        long cmp = 0, cnt = 0;
        while (num >= cmp) {
            cmp += 1 << (cnt++);
        }
        --cnt;
        
        string res = "";
        for (int i = cnt-1; i >= 0; --i) {
            long base = (1 << i) - 1, last = num - base;
            long upbase = 1 << (i+1);
            // base - 1 == 均为0
            if (last >= upbase) {
                res += '1';
                num -= upbase;
            } else {
                res += '0';
                num -= upbase/2;
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    for (int i = 0; i < 100; ++i) {
        string res = sol.encode(i);
        cout << i << ":\t\t" << res << endl;
    }
    return 0;
}
