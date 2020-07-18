#include <iostream>
using namespace std;

void heapify(int A[], int n, int i) {
    // Assume left child and right child of A[i] are max heaps
    int l = i * 2 + 1;
    int r = i * 2 + 2;
    int largest = i;
    if (l < n && A[l] >= A[largest]) {
        largest = l;
    }
    if (r < n && A[r] >= A[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(A[i], A[largest]);
        heapify(A, n, largest);
    }
}

void build_heap(int A[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(A, n, i);
    }
}

void heap_sort(int A[], int n) {
    build_heap(A, n);
    for (int i = n-1; i > 0; i--) {
        swap(A[0], A[i]);
        heapify(A, i, 0);
    }
}

int main() {
    int A[] = {3,6,0,9,4,5,7,2,8,1};
    heap_sort(A, 10);
    for (int a : A) {
        cout << a << endl;
    }
    return 0;
}
