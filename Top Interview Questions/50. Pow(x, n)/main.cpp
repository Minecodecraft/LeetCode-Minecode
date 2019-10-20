//
//  main.cpp
//  50. Pow(x, n)
//
//  Created by 边俊林 on 2019/10/20.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

#include <map>
#include <set>
#include <queue>
#include <cfloat>
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
    double EPS = 1e-10;
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n == INT_MIN) {
            x *= x;
            n >>= 1;
        }
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        return (n & 1) ? x * myPow(x*x, n/2) : myPow(x*x, n/2);
    }
};

int main() {
    Solution sol = Solution();
//    double x = 2.00;
//    int n = 10;
//    double x = 2.100;
//    int n = 3;
//    double x = 2.00;
//    int n = -2;
//    double x = -1.00;
//    int n = 3;
//    double x = -2.00;
//    int n = 2;
    double x = 1.00000;
    int n = -2147483648;
    double res = sol.myPow(x, n);
    cout << res << endl;
    return 0;
}
