//
//  main.cpp
//  C
//
//  Created by 边俊林 on 2019/11/30.
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
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        ns = vector<Node> (nodes, Node(0));
        for (int i = 0; i < value.size(); ++i) {
            ns[i].val = value[i];
            if (parent[i] != -1) {
                ns[parent[i]].chd.push_back(i);
            }
        }
        // count;
        countSum(0);
        int res = 0;
        dfs(0, res);
        return res;
    }
    
private:
    struct Node {
        int val;
        int sum = 0;
        vector<int> chd;
        
        Node(int val) : val(val) { }
    };
    vector<Node> ns;
    
    void dfs(int idx, int& cnt) {
        if (ns[idx].sum == 0) return;
        cnt++;
        for (int i = 0; i < ns[idx].chd.size(); ++i) {
            int nxt = ns[idx].chd[i];
            dfs(nxt, cnt);
        }
    }
    
    void countSum(int idx) {
        int sum = 0;
        for (int i = 0; i < ns[idx].chd.size(); ++i) {
            int nxt = ns[idx].chd[i];
            countSum(nxt);
            sum += ns[nxt].sum;
        }
        sum += ns[idx].val;
        ns[idx].sum = sum;
    }
};

int main() {
    Solution sol = Solution();
    int nodes = 7;
    vector<int> p = {
        -1,0,0,1,2,2,2
    };
    vector<int> v = {
        1,-2,4,0,-2,-1,-1
    };
    int res = sol.deleteTreeNodes(nodes, p, v);
    cout << res << endl;
    return 0;
}
