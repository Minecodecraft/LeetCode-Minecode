//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/11/16.
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
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        set<string> res;
        int sz = synonyms.size();
        for (int i = 0; i < sz; ++i) {
            synonyms.push_back({synonyms[i][1], synonyms[i][0]});
        }
        dfs(synonyms, text, res);
        return vector<string> (res.begin(), res.end());
    }
    
private:
    void dfs(vector<vector<string>>& syn, string text, set<string>& vis) {
        if (vis.count(text)) return;
        vis.insert(text);
        
        for (int i = 0; i < syn.size(); ++i) {
            auto& pir = syn[i];
            
            string::size_type pos = 0u;
            while((pos = text.find(pir[0], pos)) != string::npos){
                if ((pos < 1 || text[pos-1]==' ') && (pos+pir[0].length()>=text.length() || text[(pos+pir[0].length())]==' ')) {
                    string newstr = text;
                    newstr.replace(pos, pir[0].length(), pir[1]);
                    pos += pir[1].length();
                    dfs(syn, newstr, vis);
                } else {
                    pos += pir[0].length();
                }
            }
        }
    }
};

int main() {
    Solution sol = Solution();
    vector<vector<string>> syns = {
//        {"happy","joy"},
//        {"sad","sorrow"},
//        {"joy","cheerful"}
//        {"a","QrbCl"}
        {"a", "b"}, {"c", "d"}, {"e", "f"}
    };
//    string s = "I am happy today but was sad yesterday";
//    string s = "d QrbCl ya ya NjZQ";
    string s = "a c e";
    auto res = sol.generateSentences(syns, s);
    for_each(begin(res), end(res), [](string str) { cout << str << endl; });
    return 0;
}
