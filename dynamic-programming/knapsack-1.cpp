/**
 * @brief This is an implementation of the 0-1 knapsack problem
 * @link https://atcoder.jp/contests/dp/tasks/dp_d
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

int knapsack(int n, int v[], int w[], int W) {
    int M[n+1][W+1];
    
    for (int X = 0; X <= W; X++) {
        M[0][X] = 0;
    }
    
    for (int i = 0; i <= n; i++) {
        M[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int X = 0; X <= W; X++) {
            if (w[i] > X) {
                M[i][X] = M[i-1][X];
            }
            else {
                int use = v[i] + M[i-1][X - w[i]];
                int not_use = M[i-1][X];
                M[i][X] = max(use, not_use);
            }
        }
    }
    
    return M[n][W];
}

int32_t main(int32_t argc, char const *argv[]) {
    int n, W;
    cin >> n >> W;
    
    int v[n+1], w[n+1];
    v[0] = 0;
    w[0] = 0;
    for (int i = 1; i <= n; i++) {
        int value, weight;
        cin >> weight >> value;
        v[i] = value;
        w[i] = weight;
    }
    
    cout << knapsack(n, v, w, W) << endl;

    return 0;
}