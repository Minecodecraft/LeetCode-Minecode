//
//  main.cpp
//  274. H-Index
//
//  Created by Jaylen Bian on 1/2/21.
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
// Solution 1: Use sorting, O(nlogn)
/*
class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] >= (n-i))
                return n-i;
        }
        return res;
    }
};
 */

// Solution 2: Use counting, O(n)
/*
class Solution {
public:
    int hIndex(vector<int>& arr) {
        int n = arr.size();
        vector<int> cnt (n + 1, 0);
        for (int i = 0; i < n; ++i)
            cnt[min(n, arr[i])]++;
        int res = n;
        for (int sum = cnt[res]; res > sum; sum += cnt[res])
            --res;
        return res;
    }
};
 */

// Solution 3: Use Binary Search O(nlogn)
class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        sort(c.begin(), c.end());

        int l = 0, r = n;
        // [l, r)
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (c[mid] < n - mid) l = mid+1;
            else r = mid;
        }
        return n-l;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> arr = {
//        3, 0, 6, 1, 5
//        100
        1, 2
    };
    int res = sol.hIndex(arr);
    cout << res << endl;
    return 0;
}
