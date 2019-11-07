//
//  main.cpp
//  1007. Minimum Domino Rotations For Equal Row
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
// Solution 1: O(n) with ungly code, 214ms, let's be concise!
/*
class Solution {
public:
    int minDominoRotations(vector<int>& a, vector<int>& b) {
        bool cana = true, canb = true;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != a[0] && b[i] != a[0])
                cana = false;
            if (a[i] != b[0] && b[i] != b[0])
                canb = false;
        }
        if (!cana && !canb)
            return -1;

        int resa = cana ? 0 : INT_MAX;
        int resb = canb ? 0 : INT_MAX;
        if (cana) {
            int same = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] != a[0]) ++resa;
                else if (b[i] == a[0]) ++same;
            }
            resa = min(resa, (int)a.size()-resa-same);
        }
        if (canb) {
            int same = 0;
            for (int i = 0; i < a.size(); ++i) {
                if (b[i] != b[0]) ++resb;
                else if (a[i] == b[0]) ++same;
            }
            resb = min(resb, (int)a.size()-resb-same);
        }
        return min(resa, resb);
    }
};
 */

// Solution 2: The concislly version of solution1 🏆
/*
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int tmla = A[0], tmlb = B[0];
        int atoa = 0, atob = 0, btoa = 0, btob = 0;
        bool cana = true, canb = true;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] != tmla && B[i] != tmla) cana = false;
            if (A[i] != tmlb && B[i] != tmlb) canb = false;
            atoa += A[i] == tmla;
            atob += A[i] == tmlb;
            btoa += B[i] == tmla;
            btob += B[i] == tmlb;
        }
        if (!cana && !canb) return -1;
        return (int)A.size() - max(max(atoa, atob), max(btoa, btob));
    }
};
 */

// Solution 3: A clever way, it's interesting.
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> cnta (7, 0);
        vector<int> cntb (7, 0);
        vector<int> same (7, 0);
        for (int i = 0; i < A.size(); ++i) {
            cnta[A[i]]++;
            cntb[B[i]]++;
            if (A[i] == B[i])
                same[A[i]]++;
        }
        for (int i = 1; i <= 6; ++i) {
            if (cnta[i] + cntb[i] - same[i] == A.size())
                return A.size() - max(cnta[i], cntb[i]);
        }
        return -1;
    }
};

int main() {
    Solution sol = Solution();

    int res = sol.minDominoRotations(a, b);
    cout << res << endl;
    return 0;
}
