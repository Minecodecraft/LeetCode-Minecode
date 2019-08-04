//
//  main.cpp
//  126. Word Ladder II
//
//  Created by 边俊林 on 2019/8/1.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/word-ladder-ii/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <cmath>
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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        vector<string> path = {beginWord};
        vector<bool> vis (wordList.size(), false);
        int minn = INT_MAX;
        findCore(beginWord, endWord, wordList, path, vis, res, 0, minn);
        vector<vector<string>> rres;
        for (int i = 0; i < res.size(); ++i) {
            if (res[i].size() == minn)
                rres.push_back(res[i]);
        }
        return rres;
    }

private:
    void findCore(string beg, string end, vector<string>& wl, vector<string>& path, vector<bool> vis, vector<vector<string>>& res, int depth, int& minn) {
        if (beg == end) {
            res.push_back(path);
            minn = min(minn, (int)path.size());
            return;
        }
        if (depth >= wl.size() || depth > minn) return;

        for (int i = 0; i < wl.size(); ++i) {
            if (canPickup(beg, wl[i]) && !vis[i]) {
                vis[i] = true;
                path.push_back(wl[i]);
                findCore(wl[i], end, wl, path, vis, res, depth+1, minn);
                path.pop_back();
                vis[i] = false;
            }
        }
    }

    bool canPickup(string ori, string tar) {
        int cnt = 0;
        for (int i = 0; i < tar.length(); ++i) {
            if (ori[i] != tar[i]) cnt++;
        }
        return cnt == 1;
    }
};

void printVector(vector<string> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c", it==v.begin() ? '\0' : ' ');
        cout << *it;
    }
    printf("]\n");
}
void printVectors(vector<vector<string>> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printVector(*it);
    }
    printf("]\n");
}

int main() {
    Solution sol = Solution();
//    string b = "hit";
//    string e = "cog";
//    vector<string> wl = {"hot","dot","dog","lot","log","cog"};
    string b = "qa";
    string e = "sq";
    vector<string> wl = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    auto res = sol.findLadders(b, e, wl);
    printVectors(res);
    return 0;
}
