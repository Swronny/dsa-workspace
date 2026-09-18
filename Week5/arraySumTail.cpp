int arraySum(int array[], int n, int total) {
    if (n == 0) {
        return 0;
    }

    return arraySum(array, n - 1, total + array[n-1]);
}