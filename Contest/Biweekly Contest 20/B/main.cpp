//
//  main.cpp
//  B
//
//  Created by 边俊林 on 2020/2/22.
//  Copyright © 2020 边俊林. All rights reserved.
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
class Cashier {
private:
    int n;
    int cnt;
    int dct;
    unordered_map<int, double> pris;

public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->dct = discount;
        this->cnt = 0;
        for (int i = 0; i < products.size(); ++i) {
            pris[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount) {
        double sum = 0;
        for (int i = 0; i < product.size(); ++i) {
            sum += pris[product[i]] * amount[i];
        }
        cnt = (cnt+1) % n;
        if (cnt % n == 0)
            sum *= (100 - dct) / 100.0;
        return sum;
    }
};

int main() {

    return 0;
}
