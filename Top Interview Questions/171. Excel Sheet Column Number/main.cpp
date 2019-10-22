//
//  main.cpp
//  171. Excel Sheet Column Number
//
//  Created by 边俊林 on 2019/10/22.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    int titleToNumber(string s) {
        int res = 0, idx = 0;
        while (idx < s.size()) {
            res *= 26;
            res += s[idx]-'A'+1;
            ++idx;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "A";
//    string s = "AB";
    string s = "ZY";
    int res = sol.titleToNumber(s);
    cout << res << endl;
    return 0;
}
