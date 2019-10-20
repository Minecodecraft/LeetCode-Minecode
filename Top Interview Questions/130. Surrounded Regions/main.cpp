//
//  main.cpp
//  130. Surrounded Regions
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
    void solve(vector<vector<char>>& board) {
        int rows = board.size(), cols = rows ? board[0].size() : 0;
        vector<vector<bool>> vis (rows, vector<bool> (cols, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < cols; ++i) q.emplace(0, i);
        for (int i = 1; i < rows; ++i) q.emplace(i, cols-1);
        for (int i = cols-2; i >= 0; --i) q.emplace(rows-1, i);
        for (int i = rows-2; i > 0; --i) q.emplace(i, 0);

        int dir[5] = {0, 1, 0, -1, 0};

        while (q.size()) {
            auto pir = q.front(); q.pop();
            int row = pir.first, col = pir.second;
            if (vis[row][col] || board[row][col] == 'X')
                continue;
            vis[row][col] = true;
            for (int i = 0; i < 4; ++i) {
                int tor = row + dir[i];
                int toc = col + dir[i+1];
                if (tor>=0 && tor<rows && toc>=0 && toc<cols
                    && !vis[tor][toc] && board[tor][toc] == 'O')
                    q.emplace(tor, toc);
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O' && !vis[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<string> strs = {
//        "XXXX", "XOOX", "XXOX", "XOXX"
//        "O"
        "OXO", "XOX", "OXO"
    };
    vector<vector<char>> mat;
    for (auto& str: strs)
        mat.push_back(vector<char>(str.begin(), str.end()));
    sol.solve(mat);
    cout << mat.size() << endl;
    return 0;
}
