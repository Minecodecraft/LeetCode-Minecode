//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2019/12/28.
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
typedef long long ll;
typedef pair<int,int> P;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 0x3f3f3f3f
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> sum (n+1, 0);
        for (int i = 0; i < n; ++i)
            sum[i+1] = sum[i] + arr[i];
        int l = 0, r = target;
        long mindif = INT_MAX, val = 0;
        for (int i = l; i <= r; ++i) {
            int left = POSU(arr, i);
            int curtar = sum[left] + (n-left) * i;
            if (mindif > abs(curtar-target)) {
                mindif = abs(curtar-target);
                val = i;
            }
        }
        return val;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol = Solution();
    vector<int> arr = {
//        4, 9, 3
        2, 3, 5
    };
    int target = 10;
    int res = sol.findBestValue(arr, target);
    cout << res << endl;

    return 0;
}
