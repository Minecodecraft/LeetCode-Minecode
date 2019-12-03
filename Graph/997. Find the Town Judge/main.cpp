//
//  main.cpp
//  997. Find the Town Judge
//
//  Created by 边俊林 on 2019/12/3.
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
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> ind (N+1, 0);
        vector<int> oud (N+1, 0);
        for (auto& edge: trust) {
            oud[edge[0]]++;
            ind[edge[1]]++;
        }
        for (int i = 1; i <= N; ++i)
            if (ind[i] == N-1 && oud[i] == 0)
                return i;
        return -1;
    }
};

int main() {

    return 0;
}
