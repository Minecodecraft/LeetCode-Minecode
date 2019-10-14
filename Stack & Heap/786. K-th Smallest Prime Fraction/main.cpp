//
//  main.cpp
//  786. K-th Smallest Prime Fraction
//
//  Created by 边俊林 on 2019/10/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/k-th-smallest-prime-fraction/
\* ------------------------------------------------------ */

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
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        double l = 0.0, r = 1;
        while (r-l > DIF) {
            double mid = l + (r-l) / 2.0;
            if (count(A, mid) < K)
                l = mid + DIF;
            else
                r = mid;
        }
        vector<int> res;
        double maxval = 0;
        vector<int> maxpir (2, 0);
        for (int q = 1; q < A.size(); ++q) {
            // p / q <= tar  ->   p <= q*tar
            double maxp = (double)A[q] * r;
            auto it = upper_bound(A.begin(), A.begin()+q, maxp);
            if (it == A.begin()) continue;
            int p = *(--it);
            double fac = (double)p / A[q];
            if (fac > maxval && fac <= maxp) {
                maxval = fac;
                maxpir[0] = p;
                maxpir[1] = A[q];
            }
        }
        return maxpir;
    }

private:
    double EPS = 1e-4;
    double DIF = 1e-8;

    int count(vector<int>& A, double tar) {
        int cnt = 0;
        for (int q = 0; q < A.size(); ++q) {
            // p / q <= tar  ->   p <= q*tar
            double maxp = (double)A[q] * tar;
            cnt += upper_bound(A.begin(), A.begin()+q, maxp) - A.begin();
        }
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> A = {
        1, 2, 3, 5
//        1, 7
//        1,2029,3209,3517,3823,4933,8209,8893,12763,12799,14197,14387,18973,19207,23747,24547,24953,25247,25763,27043
    };
    int K = 3;
//    int K = 1;
    vector<int> res = sol.kthSmallestPrimeFraction(A, K);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}
