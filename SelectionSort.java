class SelectionSort {
    public static void sort(int[] A) {
        int n = A.length;
        for (int i = 0; i < n; i++) {
            int minIndex = i;
            for (int j = i+1; j < n; j++) {
                if (A[j] < A[minIndex]) {
                    minIndex = j;
                }
            }
            // swap
            int temp = A[i];
            A[i] = A[minIndex];
            A[minIndex] = temp;
        }
    }
    public static void main(String[] args) {
        int A[] = new int[] { 3,6,9,4,5,7,2,8,1 };
        SelectionSort.sort(A);
        for (int a : A) {
            System.out.println(a);
        }
    }
}
