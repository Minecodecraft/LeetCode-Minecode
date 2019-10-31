//
//  main.cpp
//  350. Intersection of Two Arrays II
//
//  Created by 边俊林 on 2019/10/31.
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0;
        vector<int> res;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] == nums2[p2]) {
                res.push_back(nums1[p1]);
                ++p1; ++p2;
            } else if (nums1[p1] > nums2[p2]) {
                ++p2;
            } else {
                ++p1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> n1 = {
        1, 2, 2, 1
    };
    vector<int> n2 = {
        2, 2
    };
    auto res = sol.intersect(n1, n2);
    cout << res.size() << endl;
    return 0;
}
