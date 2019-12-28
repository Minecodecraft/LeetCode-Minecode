//
//  main.cpp
//  D
//
//  Created by 边俊林 on 2019/12/28.
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
typedef long long ll;
typedef pair<int,int> P;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 0x3f3f3f3f
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n = board.size(), m = board[0].size();
        auto res = dfs(board, n-1, m-1);
        if (res.first == -1)
            return {0, 0};
        return {res.first, res.second};
    }

private:
    int n, m;
    int MOD = 1e9 + 7;
    vector<int> dx = {-1, -1, 0};
    vector<int> dy = {0, -1, -1};
    unordered_map<int, pair<int, int>> cnt; // from (x, y) count

    pair<int, int> dfs(vector<string>& board, int x, int y) {
        if (x == 0 && y == 0)
            return {0, 1};
//        if (board[x][y] == 'X')
//            return {-1, 0};

        int key = x * 1234 + y;
        if (cnt.count(key)) return cnt[key];
        int maxsc = -1, curcnt = 0, val = board[x][y]=='S' ? 0 : board[x][y] - '0';

        for (int i = 0; i < dx.size(); ++i) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if (tx >= 0 && ty >= 0 && board[x][y] != 'X') {
                auto nxt = dfs(board, tx, ty);
                if (nxt.first > maxsc) {
                    maxsc = nxt.first;
                    curcnt = nxt.second;
                } else if (nxt.first == maxsc) {
                    curcnt += nxt.second;
                }
            }
        }
        if (maxsc == -1)
            return cnt[key] = {-1, 0};
        return cnt[key] = make_pair(maxsc + val, curcnt % MOD);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol = Solution();
    vector<string> mat = {
//        "E23", "2X2", "12S"
//        "E12","1X1","21S"
        "E11","XXX","11S"
    };
    auto res = sol.pathsWithMaxScore(mat);
    cout << res[0] << ", " << res[1] << endl;

    return 0;
}
