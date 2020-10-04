//
//  main.cpp
//  157. Read N Characters Given Read4
//
//  Created by Jaylen Bian on 10/4/20.
//  Copyright © 2020 边俊林. All rights reserved.
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
/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int tot = 0, readcnt = 4;
        while (readcnt == 4 && tot < n) {
            readcnt = read4(buf + tot);
            tot += readcnt;
        }
        return min(tot, n);
    }
};

int main() {

    return 0;
}
