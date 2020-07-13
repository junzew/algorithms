class MergeSort {
    private static void merge(int A[], int lo, int mid, int hi) {
        // Assume A[lo .. mid] and A[mid+1 .. hi] are both sorted
        int n1 = mid - lo + 1;
        int n2 = hi - mid;
        // create temp arrays
        int L[] = new int[n1];
        int R[] = new int[n2];

        // copy data to L and R
        for (int i = 0; i < n1; i++) {
            L[i] = A[lo + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = A[mid + j];
        }

        for (int i = 0, j = 0, k = lo; k < hi; k++) {
            if (L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            } else {
                A[k] = R[i];
                j++;
            }
        }
    }
    private static void msort(int A[], int lo, int hi) {
        if (lo < hi) {
            int mid = (lo + hi) / 2;
            msort(A, lo, mid);
            msort(A, mid+1, hi);
            merge(A, lo, mid, hi);
        }
    }
    public static void sort(int A[]) {
        msort(A, 0, A.length - 1);
    }
    public static void main(String[] args) {
        int A[] = new int[] { 3,6,9,4,5,7,2,8,1 };
        QuickSort.sort(A);
        for (int a : A) {
            System.out.println(a);
        }
    }
}
