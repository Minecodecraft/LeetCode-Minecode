//
//  main.cpp
//  405. Convert a Number to Hexadecimal
//
//  Created by Jaylen Bian on 11/26/20.
//  Copyright © 2020 边俊林. All rights reserved.
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
    const string hex = "0123456789abcdef";
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        unsigned int n = num;
        string res = "";
        while (n) {
            res = hex[n & 0xf] + res;
            n >>= 4;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    int num = 16;
    string res = sol.toHex(num);
    cout << res << endl;
    return 0;
}
