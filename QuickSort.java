class QuickSort {
    private static int partition(int A[], int lo, int hi) {
        int pivot = A[hi];
        int i = lo;
        for (int j = lo; j < hi; j++) {
            if (A[j] <= pivot) {
                // swap A[i] with A[j]
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i++;
            }
        }
        // swap A[i] with A[hi]
        int temp = A[i];
        A[i] = A[hi];
        A[hi] = temp;

        return i;
    }
    private static void qsort(int A[], int lo, int hi) {
        if (lo < hi) {
            int p = partition(A, lo, hi);
            qsort(A, lo, p - 1);
            qsort(A, p + 1, hi);
        }
    }
    public static void sort(int A[]) {
        qsort(A, 0, A.length - 1);
    }
    public static void main(String[] args) {
        int A[] = new int[] { 3,6,9,4,5,7,2,8,1 };
        QuickSort.sort(A);
        for (int a : A) {
            System.out.println(a);
        }
    }
}
