/**
 * @brief This is an implementation of the Counting sort
 * 
 * To use counting sort, it is assumed that the elements
 * of the array are all integers in the range [0, k].
 * 
 * We usually use counting sort when k = O(n), 
 * which case the running time is Θ(n).
 * 
 * Counting sort is stable: numbers with the same value 
 * appear in the output array in the same order as they do
 * in the input array.
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

void counting_sort(vector<int>& A, vector<int>& B, int k) {
    vector<int> C(k+1, 0);
    
    for (int i = 0; i < A.size(); i++) {
        C[A[i]]++;
    }
    for (int i = 1; i <= k; i++) {
        C[i] += C[i-1];
    }
    for (int i = A.size()-1; i >= 0; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
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
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);
    for (int j = 0; j < n; j++) {
        cin >> A[j];
    }

    counting_sort(A, B, k);
    
    cout << to_string(B) << endl;

    return 0;
}