#include <bits/stdc++.h>
using namespace std;


int knapsack(int n, int v[], int w[], int W) {
    int M[n+1][W+1];
    
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
                int use = v[i] + M[i-1][X - w[i]];
                int not_use = M[i-1][X];
                M[i][X] = max(use, not_use);
            }
        }
    }
    
    return M[n][W];
}

int main(int argc, char const *argv[]) {
    int n, W;
    cin >> n >> W;
    
    int v[n+1], w[n+1];
    v[0] = 0;
    w[0] = 0;
    for (size_t i = 1; i <= n; i++) {
        int value, weight;
        cin >> weight >> value;
        v[i] = value;
        w[i] = weight;
    }
    
    cout << "Answer: ";
    cout << knapsack(n, v, w, W) << endl;

    return 0;
}