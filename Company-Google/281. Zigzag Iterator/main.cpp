//
//  main.cpp
//  281. Zigzag Iterator
//
//  Created by Jaylen Bian on 7/26/20.
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
class ZigzagIterator {
    vector<int> arr;
    int p;

public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int p1, p2;
        p1 = p2 = 0;
        int n1 = v1.size(), n2 = v2.size();
        while (p1 < n1 || p2 < n2) {
            if (p1 < n1) {
                arr.push_back(v1[p1++]);
            }
            if (p2 < n2) {
                arr.push_back(v2[p2++]);
            }
        }
        p = 0;
    }

    int next() {
        return arr[p++];
    }

    bool hasNext() {
        return p < arr.size();
    }
};

int main() {

    return 0;
}
