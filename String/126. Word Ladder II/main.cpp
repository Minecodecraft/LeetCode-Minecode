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
        if (beginWord == endWord)
            return {{beginWord}};
        vector<vector<string>> paths;
        vector<string> path = {beginWord};
        unordered_set<string> wl (wordList.begin(), wordList.end());
        unordered_set<string> q1, q2;
        unordered_map<string, vector<string>> mp;
        if (wl.find(endWord) == wl.end())
            return {};
        q1.insert(beginWord);
        q2.insert(endWord);
        wl.erase(beginWord);
        wl.erase(endWord);
        if (findPath(q1, q2, wl, mp, 0))
            getPath(beginWord, endWord, path, paths, mp);
        return paths;
    }

private:
    // 0 frontaled 1 reversed
    bool findPath(unordered_set<string>& q1, unordered_set<string>& q2, unordered_set<string> wl, unordered_map<string, vector<string>>& mp, int dir) {
        if (q1.empty()) return false;
        if (q1.size() > q2.size())
            return findPath(q2, q1, wl, mp, 1-dir);

        bool match = false;
        unordered_set<string> tmp;
        vector<string> removelist;
        for (auto it = q1.begin(); it != q1.end(); ++it) {
            string word = *it;
            for (int i = 0; i < word.length(); ++i) {
                char ch = word[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (ch == j) continue;
                    word[i] = j;
                    if (q2.find(word) != q2.end()) {
                        match = true;
                        dir == 0 ? mp[*it].push_back(word) : mp[word].push_back(*it);
                    } else if (!match && wl.find(word) != wl.end()) {
                        tmp.insert(word);
                        removelist.push_back(word);
                        dir == 0 ? mp[*it].push_back(word) : mp[word].push_back(*it);
                    }
                }
                word[i] = ch;
            }
        }
        for (auto word: removelist)
            wl.erase(word);
        return match || findPath(tmp, q2, wl, mp, dir);
    }

    void getPath(string beg, string end, vector<string>& path, vector<vector<string>>& paths, unordered_map<string, vector<string>>& mp) {
        if (beg == end) {
            paths.push_back(path);
        } else {
            for (auto word: mp[beg]) {
                path.push_back(word);
                getPath(word, end, path, paths, mp);
                path.pop_back();
            }
        }
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
    string b = "hit";
    string e = "cog";
    vector<string> wl = {"hot","dot","dog","lot","log"};
//    string b = "hit";
//    string e = "cog";
//    vector<string> wl = {"hot","dot","dog","lot","log","cog"};
//    string b = "qa";
//    string e = "sq";
//    vector<string> wl = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    auto res = sol.findLadders(b, e, wl);
    printVectors(res);
    return 0;
}
