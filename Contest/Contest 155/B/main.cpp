//
//  main.cpp
//  B
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
#define ll long long

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        long long l = 0, r = INT_MAX;
        while (r > l) {
            long long mid = l + (r-l) / 2;
            if (equalOrLarge(n, mid, a, b, c))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }

private:
    bool equalOrLarge(int n, long long num, int a, int b, int c) {
        long long res = num/a + num/b + num/c
                        - num/_lcm(a, b) - num/_lcm(a, c) - num/_lcm(b, c)
                        + num/_lcm(a, _lcm(b, c));
        return res >= n;
    }

    long long _gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return _gcd(b, a % b);
    }

    long long _lcm(long long a, long long b) {
        return a / _gcd(a, b) * b;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 1000000000;
//    int a = 2, b = 217983653, c = 336916467;
//    int n = 3;
//    int a = 2, b = 3, c = 5;
    int n = 4;
    int a = 2, b = 3, c = 4;
    int res = sol.nthUglyNumber(n, a, b, c);
    cout << res << endl;
    return 0;
}
