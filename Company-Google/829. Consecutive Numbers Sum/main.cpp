//
//  main.cpp
//  829. Consecutive Numbers Sum
//
//  Created by Jaylen Bian on 3/28/21.
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
    int consecutiveNumbersSum(int n) {
        int res = 1;
        for (int i = 2; i < sqrt(2 * n); ++i) {
            if ((n - (i * (i - 1)) / 2) % i == 0)
                ++res;
        }
        return res;
    }
};

int main() {

    return 0;
}
