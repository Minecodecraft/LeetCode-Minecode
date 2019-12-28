//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/12/27.
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

const int MAXN = 1e5+10;

int kase, n, m;
int arr[MAXN];
int brr[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> kase;
    while (kase--) {
        cin >> n >> m;

        unordered_map<int, int> mp;
        unordered_set<int> vis;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            mp[arr[i]] = i;
        }
        for (int i = 0; i < m; ++i) {
            cin >> brr[i];
        }
        int bp = 0, ap = 0, unused = 0, res = 0;
        while (bp < m) {
            int tmp_ap = ap, tmp_bp = bp;
            while (arr[ap] != brr[bp]) {
                vis.insert(arr[ap++]);
                ++res;
            }
            vis.insert(arr[ap++]);
            while (bp < m && vis.count(brr[bp])) {
                ++bp; ++res;
            }
            unused += ap - tmp_ap - 1;
            res += unused;
        }
        cout << res << endl;
    }

    return 0;
}
