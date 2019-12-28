//
//  main.cpp
//  B
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

ll kase, n, s;
vector<ll> sum;
vector<int> num;

void solve() {
    cin >> n >> s;
    sum = vector<ll> (n+1, 0);
    num = vector<int> (n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
        sum[i+1] = sum[i] + num[i];
    }
    int noskip = POSU(sum, s)-1;
    int skip = INT_MIN, skipp = 0, tmp;

    for (int i = 0; i < n; ++i) {
        tmp = POSU(sum, s+num[i])-2;
        if (tmp > skip) {
            skip = tmp;
            skipp = i;
        }
        if (sum[i+1] > s) break;
    }
    if (noskip >= skip)
        cout << "0" << endl;
    else
        cout << skipp+1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> kase;
    while (kase--) {
        solve();
    }

    return 0;
}
