class InsertionSort {
    public static void sort(int A[]) {
        int n = A.length;
        for (int i = 1; i < n; i++) {
            int key = A[i];
            int j = i - 1;
            while(j >= 0 && A[j] > key) {
                // shift right by 1
                A[j+1] = A[j];
                j--;
            }
            A[j+1] = key;
        }
    }
    public static void main(String[] args) {
        int [] A = new int[]{1,3,5,7,2,4,6,9,8};
        InsertionSort.sort(A);
        for (int a : A) {
            System.out.println(a);
        }

    }
}
