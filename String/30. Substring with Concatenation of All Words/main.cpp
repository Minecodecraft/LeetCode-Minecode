//
//  main.cpp
//  30. Substring with Concatenation of All Words
//
//  Created by 边俊林 on 2019/7/18.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode.com/problems/substring-with-concatenation-of-all-words/
\* ------------------------------------------------------ */

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/// Solution:
//
// Solution 1: Two-Map solution, time complex O(n * wcnt * wlen), sub-optimal
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> hash;
        auto slen = s.length(), wcnt = words.size();
        if (!slen || !wcnt) return {};
        auto wlen = words[0].length();
        for (auto i = 0; i < words.size(); ++i)
            hash[words[i]]++;
        vector<int> res;
        unordered_map<string, int> vis;
        for (int i = 0; i < slen - wcnt * wlen + 1; ++i) {
            vis.clear();
            int j = 0;
            for (; j < wcnt; ++j) {
                string word = s.substr(i + j * wlen, wlen);
                if (hash.find(word) != hash.end()) {
                    vis[word]++;
                    if (vis[word] > hash[word]) break;
                }
                else break;
            }
            if (j == wcnt) res.push_back(i);
        }
        return res;
    }
};

void printVector(vector<int> v) {
    printf("\n[");
    for (auto it = v.begin(); it != v.end(); ++it) {
        printf("%c%d", it==v.begin() ? '\0' : ' ', *it);
    }
    printf("]\n");
}

// Solution 2: 对Solution的优化，每次向后跳一个单词，如果出现不存在的单词则直接跳至当前所有匹配串后面
// 太麻烦不写，具体见 https://leetcode.wang/leetCode-30-Substring-with-Concatenation-of-All-Words.html

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

    }
};

int main() {
    Solution sol = Solution();
//    string s = "barfoothefoobarman";
//    vector<string> words = {"foo", "bar"};
//    string s = "wordgoodgoodgoodbestword";
//    vector<string> words = {"word","good","best","word"};
//    string s = "";
//    vector<string> words = {};
//    string s = "";
//    vector<string> words = {"a"};
//    string s = "wordgoodgoodgoodbestword";
//    vector<string> words = {"word","good","best","good"};
//    string s = "pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefg";
//    vector<string> words = {
//        "dhvf", "sind", "ffsl", "yekr",
//        "zwzq", "kpeo", "cila", "tfty",
//        "modg", "ztjg", "ybty", "heqg",
//        "cpwo", "gdcj", "lnle", "sefg",
//        "vimw", "bxcb"
//    };
    auto res = sol.findSubstring(s, words);
    printVector(res);
    return 0;
}
