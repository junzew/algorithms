#include <iostream>
using namespace std;
void merge(int A[], int lo, int mid, int hi) {
    int n1 = mid - lo + 1;
    int n2 = hi - mid;
    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];
    for (int i = 0; i < n1; i++) {
        L[i] = A[lo + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[mid + j + 1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0, j = 0, k = lo;
    for (k = lo; k <= hi; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    delete [] L;
    delete [] R;
}
void msort(int A[], int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi) / 2;
        msort(A, lo, mid);
        msort(A, mid+1, hi);
        merge(A, lo, mid, hi);
    }
}
void merge_sort(int A[], int n) {
    return msort(A, 0, n - 1);
}
int main() {
    int A[] = {3,5,4,2,6,1,8,0,9,7};
    merge_sort(A, 10);
    for (int a : A) {
        cout << a << endl;
    }

    return 0;
}
