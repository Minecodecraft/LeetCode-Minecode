//
//  main.cpp
//  1055. Shortest Way to Form String
//
//  Created by Jaylen Bian on 10/18/20.
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
class Solution {
public:
    int shortestWay(string source, string target) {
        int n = source.length();
        vector<bool> found (26, false);
        for (char ch: source)
            found[ch-'a'] = true;
        int p = 0;
        for (char ch: target) {
            if (!found[ch-'a'])
                return -1;
            while (source[p % n] != ch)
                ++p;
            ++p;
        }
        return (p + n - 1) / n;
    }
};

int main() {

    return 0;
}
