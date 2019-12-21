//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/12/19.
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

int n, m;
int rcnt, bcnt;
vector<int> arr (2e5+10);
unordered_map<int, int> l, r;

int main() {

    cin >> n;
    while (n--) {
        l.clear();
        r.clear();

        cin >> m;
        for (int i = 0; i < 2*m; ++i)
            cin >> arr[i];
        rcnt = bcnt = 0;
        l[0] = 0;
        for (int i = 1; i <= m; ++i) {
            if (arr[i-1] == 1) rcnt++;
            else bcnt++;
            l[rcnt-bcnt] = i;
        }
        rcnt = bcnt = 0;
        r[0] = 2*m;
        for (int i = 2*m-1; i >= m; --i) {
            if (arr[i] == 1) rcnt++;
            else bcnt++;
            r[rcnt-bcnt] = i;
        }

        int res = INT_MAX;
        for (int i = -m; i <= m; ++i) {
            if (l.count(i) && r.count(-i))
                res = min(res, r[-i] - l[i]);
        }
        cout << res << "\n";
    }

    return 0;
}
