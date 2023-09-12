/**
 * @brief This is a implementation of the 0-1 knapsack problem
 * @link https://atcoder.jp/contests/dp/tasks/dp_d
 */

#include <bits/stdc++.h>
using namespace std;

size_t knapsack(size_t n, size_t v[], size_t w[], size_t W) {
    size_t M[n+1][W+1];
    
    for (size_t X = 0; X <= W; X++) {
        M[0][X] = 0;
    }
    
    for (size_t i = 0; i <= n; i++) {
        M[i][0] = 0;
    }

    for (size_t i = 1; i <= n; i++) {
        for (size_t X = 0; X <= W; X++) {
            if (w[i] > X) {
                M[i][X] = M[i-1][X];
            }
            else {
                size_t use = v[i] + M[i-1][X - w[i]];
                size_t not_use = M[i-1][X];
                M[i][X] = max(use, not_use);
            }
        }
    }
    
    return M[n][W];
}

int main(int argc, char const *argv[]) {
    size_t n, W;
    cin >> n >> W;
    
    size_t v[n+1], w[n+1];
    v[0] = 0;
    w[0] = 0;
    for (size_t i = 1; i <= n; i++) {
        size_t value, weight;
        cin >> weight >> value;
        v[i] = value;
        w[i] = weight;
    }
    
    cout << knapsack(n, v, w, W) << endl;

    return 0;
}