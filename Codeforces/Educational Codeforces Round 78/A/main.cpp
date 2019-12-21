//
//  main.cpp
//  A
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

int n;
string s, h;
vector<int> a (26);

int main() {

    cin >> n;
    while (n--) {
        cin >> s >> h;
        int charcnt = 0;
        fill(a.begin(), a.end(), 0);
        for (char& ch: s) {
            if (a[ch-'a']++ == 0) ++charcnt;
        }
        int l = 0;
        bool flag = false;
        for (int i = 0; i < h.length(); ++i) {
            while (a[h[i]-'a'] == 0) if (a[h[l++]-'a']++ == 0) charcnt++;
            if (--a[h[i]-'a'] == 0) charcnt--;
            if (charcnt == 0) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }

    return 0;
}
