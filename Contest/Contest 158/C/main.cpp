//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/10/13.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <ctime>
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
class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        return count(0, n, rollMax);
    }

private:
    unordered_map<int, int> cache;

    int count(int from, int size, vector<int>& rollMax) {
        int key = from * 100000 + size;
        if (cache.count(key) > 0) return cache[key];

        int res = 0;
        for (int i = 1; i <= rollMax.size(); ++i) {
            if (from == i) continue;
            for (int j = 1; j <= min(size, rollMax[i-1]); ++j) {
                if (size-j == 0) res += 1;
                else res += count(i, size-j, rollMax);
                res %= (int)1e9+7;

            }
        }
        return cache[key] = res % (int)(1e9+7);
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums = {
//        1, 1, 2, 2, 2, 3
//        1,1,1,1,1,1
//        1,1,1,2,2,3
        13,3,12,14,11,11
    };
//    int n = 2;
//    int n = 3;
    int n = 5000;

    clock_t start,end;//数据类型是clock_t，需要头文件#include<time.h>

    start=clock();
    int res = sol.dieSimulator(n, nums);
    end=clock();
    cout << "Time Use: "<< (double)(end-start)/CLOCKS_PER_SEC << endl;

    cout << res << endl;
    return 0;
}
