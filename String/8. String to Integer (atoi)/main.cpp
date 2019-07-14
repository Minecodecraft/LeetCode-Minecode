//
//  main.cpp
//  8. String to Integer (atoi)
//
//  Created by 边俊林 on 2019/7/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/string-to-integer-atoi/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    Solution() {
        LC_INT_MAX = (long long)INT_MAX;
        LC_INT_MIN = (long long)INT_MIN;
    }

    int myAtoi(string str) {
        long long num = 0;
        auto slen = str.length();
        int sign, p, it;
        sign = 1;
        p = it = 0;
        vector<char> buffer(str.length(), '#');
        while (p < slen && str[p] == ' ') p++;

        if (p >= slen || !isAvailable(str[p])) return 0;
        else if (str[p] == '-' || str[p] == '+')
            sign = str[p++] == '-' ? -1 : 1;

        for (;p < slen && isdigit(str[p]); ++p) {
            buffer[it++] = str[p];
        }
        if (it == 0) return 0;

        buffer.resize(it);
        num = buffertoi(buffer) * sign;
        num = min(max(LC_INT_MIN, num), LC_INT_MAX);
        return (int)num;
    }

private:
    long long LC_INT_MIN, LC_INT_MAX;

    bool isAvailable(char ch) {
        return ch == '-' || ch == '+' || isdigit(ch);
    }

    long long buffertoi(vector<char>& buffer) {
        unsigned long long res = 0;
        for (int i = 0; i < buffer.size(); ++i) {
            res = res * 10 + (buffer[i] - '0');
            if (res > LC_INT_MAX * 2)
                return res;
        }
        return res;
    }
};

int main() {
//    string s = "123";
//    string s = "-123";
//    string s = "+123";
//    string s = "-";
//    string s = "      +1234";
//    string s = "         ";
//    string s = "hello word 123";
//    string s = "123 let's go";
//    string s = "123+111";
    string s = "-91283472332";
//    string s = "-00000000000000000000000000000001";
    Solution sol = Solution();
    auto res = sol.myAtoi(s);
    cout << res << endl;
    return 0;
}
