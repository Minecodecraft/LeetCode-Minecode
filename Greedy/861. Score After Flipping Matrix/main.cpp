//
//  main.cpp
//  861. Score After Flipping Matrix
//
//  Created by 边俊林 on 2019/11/3.
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
    int matrixScore(vector<vector<int>>& A) {
        int nr = A.size(), nc = nr ? A[0].size() : 0;
        for (int i = 0; i < nr && nc; ++i) {
            if (A[i][0] == 0) {
                for (int j = 0; j < nc; ++j)
                    A[i][j] = A[i][j] == 0 ? 1 : 0;
            }
        }
        for (int i = 0; i < nc; ++i) {
            int cnt = 0;
            for (int j = 0; j < nr; ++j)
                if (A[j][i] == 0) cnt++;
            if (cnt > nr/2) {
                for (int j = 0; j < nr; ++j)
                    A[j][i] = A[j][i] == 0 ? 1 : 0;
            }
        }
        int sum = 0;
        for (int i = 0; i < nr; ++i) {
            int num = 0;
            for (int j = 0; j < nc; ++j)
                if (A[i][j] == 1)
                    num += (1 << (nc-j-1));
            sum += num;
        }
        return sum;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> A = {
        {0,0,1,1},{1,0,1,0},{1,1,0,0}
    };
    int res = sol.matrixScore(A);
    cout << res << endl;
    return 0;
}
