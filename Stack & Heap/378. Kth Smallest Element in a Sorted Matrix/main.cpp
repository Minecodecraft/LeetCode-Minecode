//
//  main.cpp
//  378. Kth Smallest Element in a Sorted Matrix
//
//  Created by 边俊林 on 2019/10/5.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
\* ------------------------------------------------------ */

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
// Solution 1: Use heap(priority_queue), beat 16%
/*
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        if (n <= 0 || m <= 0 || n*m < k) return 0;
        auto cmp = [&matrix] (pair<int, int>& a, pair<int, int>& b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        vector<vector<bool>> vis (n, vector<bool> (m, false));
        pq.push(make_pair(0, 0));
        while (--k > 0 && pq.size()) {
            pair<int, int> pir = pq.top(); pq.pop();
            if (pir.first+1 < n && !vis[pir.first+1][pir.second])
                pq.push(make_pair(pir.first+1, pir.second)), vis[pir.first+1][pir.second] = true;
            if (pir.second+1 < m && !vis[pir.first][pir.second+1])
                pq.push(make_pair(pir.first, pir.second+1)), vis[pir.first][pir.second+1] = true;
        }
        return matrix[pq.top().first][pq.top().second];
    }
};
 */

// Solution 2: Use binary Search, beats 100% o(￣▽￣)ｄ
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        if (n <= 0 || m <= 0 || n*m < k) return 0;
        int l = matrix[0][0], r = matrix[n-1][m-1];
        while (l < r) {
            int mid = l + (r-l) / 2;
            int sum = 0;
            for (int i = 0; i < m; ++i) {
                int cnt = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                sum += cnt;
            }
            if (sum < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat {
        {1, 5, 9}, {10, 11, 13}, {12, 13, 15}
    };
    int k = 8;
    int res = sol.kthSmallest(mat, k);
    cout << res << endl;
    return 0;
}
