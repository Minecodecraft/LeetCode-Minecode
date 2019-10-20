//
//  main.cpp
//  69. Sqrt(x)
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
    double EPS = 1e-6;
public:
    int mySqrt(int x) {
        double l = 0, r = (double)x;
        while (r - l >= EPS) {
            double mid = l + (r-l) / 2;
            double tar = mid * mid;
            if (x-tar >= 0 && x-tar <= EPS) {
                l = mid;
                break;
            }
            if (tar > x)
                r = mid;
            else
                l = mid + EPS;
        }
        return (int)l;
    }
};

int main() {
    Solution sol = Solution();
    int x = 8;
    int res = sol.mySqrt(x);
    cout << res << endl;
    return 0;
}
