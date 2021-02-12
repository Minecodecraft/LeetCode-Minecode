//
//  main.cpp
//  1423. Maximum Points You Can Obtain from Cards
//
//  Created by Jaylen Bian on 2/12/21.
//  Copyright © 2021 边俊林. All rights reserved.
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
    int maxScore(vector<int>& pts, int k) {
        int n = pts.size();
        vector<long> sum (n+1, 0);
        for (int i = 0; i < n; ++i)
            sum[i+1] = sum[i] + pts[i];

        long res = 0;
        for (int i = 0; i <= k; ++i) {
            // [0, i], [n-(k-i), n]
            long tot = (sum[i] - sum[0]) + (sum[n] - sum[n-k+i]);
            res = max(res, tot);
        }
        return res;
    }
};

int main() {

    return 0;
}
