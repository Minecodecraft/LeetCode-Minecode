//
//  main.cpp
//  B
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

int n, a, b;

int main() {

    cin >> n;
    while (n--) {
        cin >> a >> b;
        int dif = abs(a-b);
        if (dif == 0)
            cout << "0\n";
        else
            for (int i = 1; ; ++i) {
                long long sum = i * (i+1) / 2;
                if ((dif&1) == (sum&1) && dif <= sum) {
                    cout << i << "\n";
                    break;
                }
            }
    }
    return 0;
}
