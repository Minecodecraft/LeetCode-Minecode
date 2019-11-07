//
//  main.cpp
//  1005. Maximize Sum Of Array After K Negations
//
//  Created by 边俊林 on 2019/11/7.
//  Copyright © 2019 边俊林. All rights reserved.
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
    int largestSumAfterKNegations(vector<int>& a, int k) {
        if (a.empty()) return 0;
        sort(begin(a), end(a));
        for (int i = 0; i < a.size(); ++i) {
            if (k > 0 && a[i] < 0)
                a[i] = -a[i], --k;
        }
        if (k & 1) {
            sort(begin(a), end(a));
            a[0] = -a[0];
        }
        return accumulate(begin(a), end(a), 0);
    }
};

int main() {
    Solution sol = Solution();
    
    return 0;
}
