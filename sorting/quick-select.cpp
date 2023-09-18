/**
 * @brief This is an implementation of the quick select
 * average case: Θ(n)
 * worst case: O(n^2)
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long

int partition(vector<int>& A, int first, int last) {
    int pivot = A[last];
    int lower_bd = first - 1;
    for (int upper_bd = first; upper_bd <= last - 1; upper_bd++) {
        if (A[upper_bd] <= pivot) {
            lower_bd++;
            swap(A[lower_bd], A[upper_bd]);
        }
    }
    swap(A[lower_bd + 1], A[last]);
    return lower_bd + 1;
}

int random(int first, int last) {
    mt19937 generator(random_device{}());
    uniform_int_distribution<int> distribution(first, last);
    return distribution(generator);
}

int randomized_partition(vector<int>& A, int first, int last) {
    int pivot = random(first, last);
    swap(A[pivot], A[last]);
    return partition(A, first, last);
}

int quick_select(vector<int>& A, int first, int last, int i) {
    if (first == last) {
      return A[first];
    }
    int pivot_index = randomized_partition(A, first, last);
    int k = pivot_index - first + 1;
    if (i == k) {
      return A[pivot_index];
    }
    else if (i < k) {
      return quick_select(A, first, pivot_index - 1, i);
    }
    else {
      return quick_select(A, pivot_index + 1, last, i - k);
    }
}

int32_t main(int32_t argc, char const *argv[]) {
    int n, i;
    cin >> n >> i;

    vector<int> elements(n);
    for (int j = 0; j < n; j++) {
        cin >> elements[j];
    }
    
    cout << quick_select(elements, 0, n-1, i) << endl;

    return 0;
}