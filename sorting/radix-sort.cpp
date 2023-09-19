/**
 * @brief This is an implementation of the Radix sort
 * 
 * Radix sort correctly sorts these numbers in Θ(d(n + k))
 * time if the stable sort it uses takes Θ(n + k) time.
 * 
 * When the number of digits is constant and k = Θ(n),
 * we can make radix sort run in linear time.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

void stable_sort(vector<int>& A, int d) {
    vector<int> C(10, 0);
    vector<int> B(A.size(), 0);

    for (int i = 0; i < A.size(); i++) {
        int count_pos = (A[i] / d) % 10;
        C[count_pos]++;
    }
    for (int i = 1; i <= 9; i++) {
        C[i] += C[i-1];
    }
    for (int i = A.size()-1; i >= 0; i--) {
        int count_pos = (A[i] / d) % 10;
        B[C[count_pos]-1] = A[i];
        C[count_pos]--;
    }
    for (int i = 0; i < A.size(); i++) {
        A[i] = B[i];
    }
}

void radix_sort(vector<int>& A) {
    int maxValue = *max_element(A.begin(), A.end());
    int d = 1;
    while (maxValue / d > 0) {
        stable_sort(A, d);
        d *= 10;
    }
}

string to_string(vector<int> A) {
    ostringstream oss;
    for (int i = 0; i < A.size(); i++) {
        oss << A[i] << " ";
    }
    return oss.str();
}

int32_t main(int32_t argc, char const *argv[]) {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int j = 0; j < n; j++) {
        cin >> A[j];
    }

    radix_sort(A);
    
    cout << to_string(A) << endl;

    return 0;
}