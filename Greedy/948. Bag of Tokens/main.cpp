//
//  main.cpp
//  948. Bag of Tokens
//
//  Created by 边俊林 on 2019/11/5.
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
    int bagOfTokensScore(vector<int>& ts, int P) {
        sort(begin(ts), end(ts));
        int l = 0, r = ts.size()-1;
        int power = P, p = 0, maxx = 0;
        while (l <= r) {
            if (power >= ts[l])
                ++p, power -= ts[l++];
            else if (p)
                power += ts[r--], --p;
            else
                break;
            maxx = max(maxx, p);

        }
        return maxx;
    }
};

int main() {

    return 0;
}
