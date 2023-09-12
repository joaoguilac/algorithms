/**
 * @brief This is a implementation of the Longest common subsequence problem (LCS)
 * @link https://atcoder.jp/contests/dp/tasks/dp_f
 */

#include <bits/stdc++.h>
using namespace std;

string LCS(string X, string Y) {
    int n = X.length();
    int m = Y.length();

    /*
    Create a vector containing "n+1"
    vectors each of size "m+1".
    */
    vector<vector<int>> c(n+1, vector<int>(m+1));
    
    // Initialize matrix
    c[0][0] = 0;
    for (size_t i = 1; i <= n; i++) {
        c[i][0] = 0;
    }
    for (size_t j = 1; j <= m; j++) {
        c[0][j] = 0;
    }

    // Calculate the size of the LCS
    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= m; j++) {
            if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    // Retrieve the sequence
    string seq = "";
    int i{n}, j{m};
    while (i != 0 && j != 0) {
        if (X[i-1] == Y[j-1]) {
            seq += X[i-1];
            i--;
            j--;
        }
        else {
            if (c[i-1][j] >= c[i][j-1]) {
                i--;
            }
            else {
                j--;
            }
        }
    }
    
    reverse(seq.begin(), seq.end());

    return seq;
}

int main(int argc, char const *argv[]) {
    string X, Y;
    cin >> X >> Y;
    
    cout << LCS(X, Y) << endl;

    return 0;
}