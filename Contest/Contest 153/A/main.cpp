//
//  main.cpp
//  A
//
//  Created by 边俊林 on 2019/9/8.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

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

/// Solution:
//
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n = distance.size();
        vector<int> sum (n+1, 0);
        for (int i = 1; i <= n; ++i)
            sum[i] = sum[i-1] + distance[i-1];

        if (start > destination)
            swap(start, destination);
        int clockwishDis = sum[destination] - sum[start];
        return min(sum[n]-clockwishDis, clockwishDis);
    }
};

int main() {
    Solution sol = Solution();
    vector<int> dis = {1, 2, 3, 4};
    int res = sol.distanceBetweenBusStops(dis, 0, 1);
    cout << res << endl;
    return 0;
}
