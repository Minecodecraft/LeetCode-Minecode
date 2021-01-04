//
//  main.cpp
//  849. Maximize Distance to Closest Person
//
//  Created by Jaylen Bian on 1/4/21.
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
// Solution 1: Use two pointer
/*
class Solution {
    int dis(int s, int e, int n) {
        cout << s << " ---- " << e << endl;
        if (s == -1 || e == n) {
            return e - s - 1;
        } else {
            return (e - s) / 2;
        }
    }
public:
    int maxDistToClosest(vector<int>& seats) {
        int l = -1, r = l, res = 0, n = seats.size();
        while (l < n) {
            r = l + 1;
            while (r < n && seats[r] == 0)
                ++r;
            res = max(res, dis(l, r, n));
            l = r;
        }
        return res;
    }
};
 */

// Solution 2: Count zero with some brilliant way.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int maxx = 0, zero = 0;
        while (seats[maxx] == 0)
            maxx++;

        for (int i = maxx + 1; i < n; ++i) {
            if (seats[i] == 0) {
                ++zero;
            } else {
                maxx = max(maxx, (zero + 1) / 2);
                zero = 0;
            }
        }
        return max(maxx, zero);
    }
};

int main() {

    return 0;
}
