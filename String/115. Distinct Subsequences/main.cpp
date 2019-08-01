//
//  main.cpp
//  115. Distinct Subsequences
//
//  Created by 边俊林 on 2019/7/31.
//  Copyright © 2019 Minecode.Link. All rights reserved.
//

/* ------------------------------------------------------ *\
 https://leetcode-cn.com/problems/Sample/description/
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
// Solution 1
/*
class Solution {
public:
    int numDistinct(string s, string t) {
        auto ls = s.length(), lt = t.length();
        if (ls < lt) return 0;
        // dp[i][j] means that the step s[0, i-1) to t[0, j-1)
        vector<vector<unsigned int>> dp (ls+1, vector<unsigned int> (lt+1, 0));
        for (int i = 0; i <= ls; ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= ls; ++i) {
            for (int j = 1; j <= lt; ++j) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[ls][lt];
    }
};
 */

// Solution 2: 优化版本
/*
class Solution {
public:
    int numDistinct(string s, string t) {
        auto ls = s.length(), lt = t.length();
        if (ls < lt) return 0;
        // dp[i][j] means that the step s[0, i-1) to t[0, j-1)
        vector<unsigned int> pre (lt+1, 0);
        vector<unsigned int> cur (lt+1, 0);

        for (int i = 1; i <= ls; ++i) {
            pre[0] = 1;
            for (int j = 1; j <= lt; ++j) {
                cur[j] = pre[j];
                if (s[i-1] == t[j-1])
                    cur[j] += pre[j-1];
            }
            fill(pre.begin(), pre.end(), 0);
            swap(cur, pre);
        }
        return pre[lt];
    }
};
 */

// Solution 3: 再优化版本
class Solution {
public:
    int numDistinct(string s, string t) {
        auto ls = s.length(), lt = t.length();
        if (ls < lt) return 0;
        // dp[i][j] means that the step s[0, i-1) to t[0, j-1)
        vector<unsigned int> dp (lt+1, 0);

        for (int i = 1; i <= ls; ++i) {
            for (int j = (int)lt; j >= 1; --j) {
                if (s[i-1] == t[j-1])
                    dp[j] = (j > 1 ? dp[j-1] : 1) + dp[j];
            }
        }
        return dp[lt];
    }
};

int main() {
    Solution sol = Solution();
    string s = "rabbbit";
    string t = "rabbit";
//    string s = "ccc";
//    string t = "c";
//    string s = "babgbag";
//    string t = "bag";
//    string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
//    string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
    auto res = sol.numDistinct(s, t);
    cout << res << endl;
    return 0;
}
