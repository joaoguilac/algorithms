/**
 * @brief This is an implementation of the quick sort
 * average case: Θ(nlogn)
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

void quick_sort(vector<int>& A, int first, int last) {
    if (first < last) {
        int pivot_index = randomized_partition(A, first, last);
        quick_sort(A, first, pivot_index - 1);
        quick_sort(A, pivot_index + 1, last);
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

    vector<int> elements(n);
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
    }

    quick_sort(elements, 0, n-1);
    
    cout << to_string(elements) << endl;

    return 0;
}