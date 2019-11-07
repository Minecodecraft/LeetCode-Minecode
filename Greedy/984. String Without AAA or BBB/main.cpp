//
//  main.cpp
//  984. String Without AAA or BBB
//
//  Created by 边俊林 on 2019/11/7.
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
    string strWithout3a3b(int A, int B) {
        string res = "";
        char cha = 'a', chb = 'b';
        int na = A, nb = B;
        if (na < nb) {
            swap(cha, chb);
            swap(na, nb);
        }
        int single = min(na, (nb+1) * 2 - na);
        int twice = (na - single)/2;
        for (int i = 0; i < single; ++i) {
            res += cha;
            if (nb) {
                res += chb;
                nb--;
            }
        }
        for (int i = 0; i < twice; ++i) {
            res += cha;
            res += cha;
            if (nb) {
                res += chb;
                nb--;
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    int A = 1, B = 2;
//    int A = 1, B = 4;
    int A = 4, B = 1;
//    int A = 2, B = 4;
//    int A = 1, B = 1;
    string res = sol.strWithout3a3b(A, B);
    cout << res << endl;
    return 0;
}
