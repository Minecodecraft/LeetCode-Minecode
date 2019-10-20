//
//  main.cpp
//  29. Divide Two Integers
//
//  Created by 边俊林 on 2019/10/20.
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
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long dvd = labs(dividend), dvs = labs(divisor);
        int res = 0;
        long sign = (dividend > 0 ^ (divisor > 0)) ? -1 : 1;
        while (dvd >= dvs) {
            long curdvs = dvs, fac = 1;
            while (curdvs << 1 <= dvd) {
                curdvs <<= 1;
                fac <<= 1;
            }
            dvd -= curdvs;
            res += fac;
        }
        return sign * res;
    }
};

int main() {
    Solution sol = Solution();
//    int a = 10, b = 3;
//    int a = 7, b = -3;
//    int a = -7, b = -3;
//    int a = -2147483648, b = -1;
//    int a = 214748367, b = 1;
    int a = -2147483648, b = 1;
    int res = sol.divide(a, b);
    cout << res << endl;
    return 0;
}
