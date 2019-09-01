//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2019/9/1.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

// https://leetcode.com/contest/weekly-contest-152

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    Solution() {

    }

    int numPrimeArrangements(int n) {
        if (n == 1) return 1;

        int pricnt = 0, noprocnt = 0;
        for (int i = 2; i <= n; ++i)
            if (table.count(i))
                pricnt++;
        noprocnt = n-pricnt;
        long long res = 1;
        for (int i = pricnt; i >= 1; --i) {
            res *= i;
            res %= MOD;
        }
        for (int i = noprocnt; i >= 1; --i) {
            res *= i;
            res %= MOD;
        }
        res %= MOD;
        return (int)res;
    }

private:
    unordered_set<int> table = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107
    };

    const int MOD = 1e9+7;
};

int main(int argc, const char * argv[]) {

    return 0;
}
