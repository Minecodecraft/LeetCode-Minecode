//
//  main.cpp
//  166. Fraction to Recurring Decimal
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
    string fractionToDecimal(int numerator, int denominator) {
        long n = numerator, d = denominator;
        int sign = n >= 0 ^ d >= 0 ? -1 : 1;
        if (numerator == 0) sign = 1;
        n = abs(n);
        d = abs(d);

        string l = to_string(n / d);
        n %= d;
        n *= 10;
        string r = "";
        unordered_map<pair<int, int>, int, hash_key> vis;
        int idx = 0, dupidx = 0;
        while (n) {
            pair<int, int> pir = make_pair(n, d);
            if (vis.count(pir)) {
                dupidx = vis[pir];
                break;
            }
            vis[pir] = idx;
            if (n < d) {
                r += '0';
                n *= 10;
            } else {
                r += to_string(n / d);
                n %= d;
                n *= 10;
            }
            idx++;
        }

        string signstr = ((sign == -1) ? "-" : "");
        while (r.size() && r.back() == '0')
            r.pop_back();

        if (r.empty())
            return signstr + l;
        if (n) {
            r.insert(dupidx, "(");
            r.push_back(')');
        }
        return signstr +  l + "." + r;
    }

private:
    struct hash_key {
        size_t operator() (const pair<int, int>& pir) const {
            return size_t(pir.first) + size_t(pir.second);
        }
    };
};

int main() {
    Solution sol = Solution();
//    int a = 1, b = 2;
//    int a = 2, b = 1;
//    int a = 2, b = 3;
//    int a = 1, b = 7;
//    int a = 1, b = 6;
//    int a = 4, b = 333;
//    int a = -50, b = 8;
//    int a = -1, b = INT_MIN;
//    int a = INT_MIN, b = 1;
    int a = 0, b = -3;
    string res = sol.fractionToDecimal(a, b);
    cout << res << endl;
    return 0;
}
