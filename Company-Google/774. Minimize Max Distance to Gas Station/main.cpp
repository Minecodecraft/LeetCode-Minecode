//
//  main.cpp
//  774. Minimize Max Distance to Gas Station
//
//  Created by Jaylen Bian on 8/12/20.
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
    const double EPS = 1e-6;
    int cnt(vector<int>& pads, double n) {
        int tot = 0;
        for (int i = 0; i < pads.size(); ++i) {
            if (pads[i] <= n) break;
            tot += ceil(pads[i] / n) - 1;
        }
        return tot;
    }

public:
    double minmaxGasDist(vector<int>& stas, int k) {
        vector<int> pads;
        for (int i = 1; i < stas.size(); ++i)
            pads.push_back(stas[i] - stas[i-1]);
        sort(pads.begin(), pads.end(), [](int a, int b) { return a >= b; });
        double l = 0.0, r = pads[0];
        while (l + EPS < r) {
            double mid = l + (r - l) / 2;
            if (cnt(pads, mid) <= k)
                r = mid;
            else
                l = mid + EPS;
        }
        return l;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {
//        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
        23,24,36,39,46,56,57,65,84,98
    };
    int k = 1;
    double res = sol.minmaxGasDist(arr, k);
    cout << res << endl;
    return 0;
}
