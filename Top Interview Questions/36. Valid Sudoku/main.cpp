//
//  main.cpp
//  36. Valid Sudoku
//
//  Created by 边俊林 on 2019/10/20.
//  Copyright © 2019 Minecode.Link. All rights reserved.
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
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> vis1(81, false), vis2(81, false), vis3(81, false);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, blockidx = i / 3 * 3 + j / 3;
                    if (vis1[i*9 + num] || vis2[j*9 + num] || vis3[blockidx*9 + num])
                        return false;
                    vis1[i*9 + num] = vis2[j*9 + num] = vis3[blockidx*9 + num] = true;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution sol = Solution();
    vector<string> rawmat = {
        "53..7....",
        "6..195...",
        ".98....6.",
        "8...6...3",
        "4..8.3..1",
        "7...2...6",
        ".6....28.",
        "...419..5",
        "....8..79",
    };
    vector<vector<char>> mat;
    for (int i = 0; i < rawmat.size(); ++i) {
        mat.push_back(vector<char> (rawmat[i].begin(), rawmat[i].end()));
    }
    bool res = sol.isValidSudoku(mat);
    cout << (res ? "true": "false") << endl;
    return 0;
}
