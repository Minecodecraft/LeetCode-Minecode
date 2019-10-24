//
//  main.cpp
//  202. Happy Number
//
//  Created by 边俊林 on 2019/10/24.
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
public:
    bool isHappy(int n) {
        unordered_set<int> vis;
        int cur = n;
        while (cur != 1) {
            if (vis.count(cur))
                return false;
            vis.insert(cur);
            cur = getHappyNumber(cur);
        }
        return true;
    }

private:
    long long getHappyNumber(int n) {
        long long res = 0;
        while (n) {
            int mod = n % 10;
            res += mod * mod;
            n /= 10;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    int n = 19;
    int n = 0;
    bool res = sol.isHappy(n);
    cout << res << endl;
    return 0;
}
