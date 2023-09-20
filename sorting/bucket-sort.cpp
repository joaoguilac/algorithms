/**
 * @brief This is an implementation of the Bucket sort
 * average case: Θ(n) + n * (2 - 1/n) = Θ(n)
 * Assumes that the input is drawn from a uniform distribution
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

void bucket_sort(vector<double>& A) {
    int n = A.size();
    vector<list<double>> B(n);

    for (int i = 0; i < n; i++) {
      B[n*A[i]].push_back(A[i]);
    }

    for (int i = 0; i < n; i++) {
        B[i].sort();
    }
    
    int index = 0;
    for (int i = 0; i < n; i++) {
        int size_list = B[i].size();
        for (int j = 0; j < size_list; j++) {
            A[index++] = B[i].front();
            B[i].pop_front();
        }
    }
}

string to_string(vector<double> A) {
    ostringstream oss;
    for (int i = 0; i < A.size(); i++) {
        oss << A[i] << " ";
    }
    return oss.str();
}

int32_t main(int32_t argc, char const *argv[]) {
    int n;
    cin >> n;

    vector<double> A(n);
    for (int j = 0; j < n; j++) {
        cin >> A[j];
    }

    bucket_sort(A);
    
    cout << to_string(A) << endl;

    return 0;
}