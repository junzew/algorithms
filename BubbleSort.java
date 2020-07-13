class BubbleSort {
    // Algorithm Design Manual p.40
    public static void sort(int[] A) {
        int n = A.length;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < i;  j++) {
                if (A[j] > A[j+1]) {
                    int temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                }
            }
        }
    }
    public static void main(String[] args) {
        int A[] = new int[] { 3,6,9,4,5,7,2,8,1 };
        BubbleSort.sort(A);
        for (int a : A) {
            System.out.println(a);
        }
    }
}
