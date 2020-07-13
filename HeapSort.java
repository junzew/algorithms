class HeapSort {
    public static void heapify(int[] A, int n, int i) {
        // Let A[i] float down in the max-heap
        // A - array
        // n - size of heap
        // i - index into the array
        // Assume: left and right children of i are both max heaps
        // but A[i] might be the smaller than its children, violating
        // the max-heap property
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;
        if (l < n && A[l] > A[largest]) {
            largest = l;
        }
        if (r < n && A[r] > A[largest]) {
            largest = r;
        }
        if (largest != i) {
            // Exchange A[i] with A[largest]
            int temp = A[i];
            A[i] = A[largest];
            A[largest] = temp;

            heapify(A, n, largest);
        }
    }
    public static void buildMaxHeap(int[] A) {
        int n = A.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(A, n, i);
        }
    }
    public static void sort(int[] A) {
        buildMaxHeap(A);

        int n = A.length;
        for (int i = n - 1; i > 0; i--) {
            // Exchange A[0] with A[i]
            int temp = A[0];
            A[0] = A[i];
            A[i] = temp;
            heapify(A, i, 0); // restore max-heap property
        }
    }
    public static void main(String[] args) {
        int[] A = new int[]{ 3,1,6,5,9,2,8,4,7 };
        HeapSort.sort(A);
        for (int a : A) {
            System.out.println(a);
        }
    }
}
