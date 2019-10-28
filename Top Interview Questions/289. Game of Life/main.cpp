//
//  main.cpp
//  289. Game of Life
//
//  Created by 边俊林 on 2019/10/26.
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
    void gameOfLife(vector<vector<int>>& board) {
        queue<int> q;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int cnt = countNei(board, i, j);
                if (board[i][j] == 1) {
                    if (cnt < 2 || cnt > 3)
                        q.push(0);
                    else
                        q.push(1);
                } else {
                    q.push(cnt == 3 ? 1 : 0);
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                board[i][j] = q.front();
                q.pop();
            }
        }
    }

private:
    int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
    int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

    int countNei(vector<vector<int>>& board, int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            int tx = x + dx[i];
            int ty = y + dy[i];
            if (tx>=0 && tx<board.size() && ty>=0 && ty<board[0].size()) {
                cnt += board[tx][ty];
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<int>> mat = {
//        {0, 1, 0},
//        {0, 0, 1},
//        {1, 1, 1},
//        {0, 0, 0},
    };
    sol.gameOfLife(mat);
    cout << mat.size() << endl;
    return 0;
}
