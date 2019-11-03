//
//  main.cpp
//  757. Set Intersection Size At Least Two
//
//  Created by 边俊林 on 2019/11/3.
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
    int intersectionSizeTwo(vector<vector<int>>& ints) {
        sort(ints.begin(), ints.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1] || a[1] == b[1] && a[0] > b[0];
        });
        int n = ints.size();
        vector<int> last(n, 2);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (last[i] <= 0) continue;
            int tar = ints[i][1];
            cnt++;
            for (int j = i; j < n; ++j) {
                if (ints[j][0] <= tar && ints[j][1] >= tar) last[j]--;
                else break;
            }
            if (last[i] > 0) {
                int btar = ints[i][1]-1;
                cnt++;
                for (int j = i; j < n; ++j) {
                    if (ints[j][0] <= btar && ints[j][1] >= btar) last[j]--;
                    else break;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
        {1, 3}, {1, 4}, {2, 5}, {3, 5}
//        {1, 2}, {2, 3}, {2, 4}, {4, 5}
//        {2,10},{3,7},{3,15},{4,11},{6,12},{6,16},{7,8},{7,11},{7,15},{11,12}
    };
    int res = sol.intersectionSizeTwo(mat);
    cout << res << endl;
    return 0;
}
