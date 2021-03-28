//
//  main.cpp
//  911. Online Election
//
//  Created by Jaylen Bian on 3/28/21.
//  Copyright © 2021 边俊林. All rights reserved.
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
class TopVotedCandidate {
    map<unsigned int, int> mp;

public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        vector<int> cnt (5010, 0);
        int maxx = 5009;
        cnt[maxx] = -1;
        for (int i = 0; i < times.size(); ++i) {
            int p = persons[i], t = times[i];
            if (++cnt[p] >= cnt[maxx]) {
                maxx = p;
                mp[t] = maxx;
            }
        }
        mp[INT_MAX] = maxx;
    }

    int q(int t) {
        auto it = mp.upper_bound(t);
        return prev(it)->second;
    }
};

int main() {
    vector<int> ps = {0,1,1,0,0,1,0};
    vector<int> ts = {0,5,10,15,20,25,30};
    TopVotedCandidate sol = TopVotedCandidate(ps, ts);
    vector<int> qs = {3, 12, 25, 15, 24, 8};
    for (int q: qs) {
        cout << sol.q(q) << endl;
    }
    return 0;
}
