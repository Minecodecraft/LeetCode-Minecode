//
//  main.cpp
//  1166. 敌兵布阵
//
//  Created by 边俊林 on 2019/10/30.
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

// 线段树


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; ++kase) {
        int n;
        cin >> n;
        vector<int> arr(n*2);
        for (int i = 0 ; i < n; ++i)
            cin >> arr[i+n];
        for (int i = n-1; i > 0; --i)
            arr[i] = arr[i<<1] + arr[i<<1|1];
        
        cout << "Case " << kase << ":\n";
        string cmd;
        int l, r;
        while (cin >> cmd) {
            if (cmd == "End") break;
            cin >> l >> r;
            if (cmd == "Query") {
                l += n - 1; r += n;
                int tot = 0;
                while (l < r) {
                    if (l & 1) tot += arr[l++];
                    if (r & 1) tot += arr[--r];
                    l >>= 1; r >>= 1;
                }
                cout << tot << "\n";
            } else if (cmd == "Add" || cmd == "Sub") {
                if (cmd == "Sub") r = -r;
                l += n-1;
                arr[l] += r;
                while (l > 1) {
                    l >>=  1;
                    arr[l] = arr[l<<1] + arr[l<<1|1];
                }
            }
        }
    }
    return 0;
}
