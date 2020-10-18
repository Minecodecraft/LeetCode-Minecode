//
//  main.cpp
//  1231. Divide Chocolate
//
//  Created by Jaylen Bian on 10/17/20.
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
    bool check(vector<int>& arr, int K, int tar) {
        int tot = 0, sum = 0, p = 0;
        while (p < arr.size()) {
            sum += arr[p++];
            if (sum >= tar) {
                sum = 0;
                ++tot;
            }
        }
        return tot >= K;
    }

public:
    int maximizeSweetness(vector<int>& arr, int K) {
        int l = 0, r = accumulate(arr.begin(), arr.end(), 0);
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (check(arr, K+1, mid))
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {
    Solution sol = Solution();
//    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    vector<int> arr = {1,2,2,1,2,2,1,2,2};
//    int K = 5;
    int K = 2;
    int res = sol.maximizeSweetness(arr, K);
    cout << res << endl;
    return 0;
}
