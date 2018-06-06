//
//  main.cpp
//  11. Container With Most Water
//
//  Created by 边俊林 on 2018/6/6.
//  Copyright © 2018 minecode. All rights reserved.
//

/* ------------------------------------------------------------------------ *\
    https://leetcode-cn.com/problems/container-with-most-water/description/
\* ------------------------------------------------------------------------ */

#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
// Use two pointer, we can get the max value by shrink the range. But must we test all the range collocation? That's O(n^2).
// We need a way to shrink purposive that we can know the max value must in these test cases.
// Consider [8, ??, ??, 6], which one to discard? 8 or 6?
// As the length of range is same, we can know that [8, ??, ??] must equal or greater than [??, ??, 6]
// Talk is cheap, see the code!

/// Tips:
//
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxx = 0, l = 0, r = (int)height.size()-1;
        while (l < r) {
            maxx = max(maxx, min(height[l], height[r]) * (r-l));
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxx;
    }
};

void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
    
    int arr[] = {2, 10, 6, 8, 3, 5, 7, 9};
    size_t size = sizeof(arr) / sizeof(int);
    vector<int> v = vector<int>(arr, arr+size);
    
    int res = sol.maxArea(v);
    
    printf("%d\n", res);
    
    return 0;
}
