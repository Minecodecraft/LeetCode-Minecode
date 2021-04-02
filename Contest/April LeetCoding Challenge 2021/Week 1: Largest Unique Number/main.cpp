//
//  main.cpp
//  Week 1: Largest Unique Number
//
//  Created by Jaylen Bian on 4/2/21.
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
    int largestUniqueNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) { return a > b; });
        int i = 0;
        while (i < arr.size()) {
            int p = i;
            while (p < arr.size() && arr[p] == arr[i]) ++p;
            if (p == i + 1)
                return arr[i];
            i = p;
        }
        return -1;
    }
};

int main() {

    return 0;
}
