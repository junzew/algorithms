#include <iostream>
using namespace std;

int partition(int A[], int lo, int hi) {
    int pivot = A[hi];
    int i = lo;
    for (int j = lo; j < hi; j++) {
        if (A[j] <= pivot) {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[hi]);
    return i;
}

void qsort(int A[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(A, lo, hi);
        qsort(A, lo, p-1);
        qsort(A, p+1, hi);
    }
}

void sort(int A[], int n) {
    return qsort(A, 0, n-1);
}

int main() {
    int A[10] = {3,5,0,4,2,6,7,1,9,8};
    sort(A, 10);
    for (int i : A) {
        cout << i << endl;
    }
    return 0;
}
