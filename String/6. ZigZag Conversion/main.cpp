//
//  main.cpp
//  6. ZigZag Conversion
//
//  Created by 边俊林 on 2019/7/14.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/zigzag-conversion/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
class Solution {
public:
    string convert(string s, int numRows) {
        int p, type;
        p = type = 0;
        int slen = s.length();
        int numCols= slen + 10;
        int zigCol;
        vector<vector<char>> zigzag = vector<vector<char>>(numRows, vector<char>(numCols, '#'));
        for (zigCol = 0; ;++zigCol) {
            int tmpRow = type == 0 ? 0 : numRows-type-1;
            int maxRow = type == 0 ? numRows-1 : tmpRow;
            while (p < slen && tmpRow <= maxRow)
                zigzag[tmpRow++][zigCol] = s[p++];
            if (p >= slen)
                break;
            type = (type+1) % (max(2, numRows)-1);
        }
        string res;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (zigzag[i][j] != '#')
                    res.push_back(zigzag[i][j]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
//    string s = "PAYPALISHIRING";
//    auto res = sol.convert(s, 3);
//    auto res = sol.convert(s, 4);
//    string s = "AB";
//    string s = "Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.";
//    auto res = sol.convert(s, 1);
    string s = "ABC";
    auto res = sol.convert(s, 2);
    cout << res << endl;
    return 0;
}
