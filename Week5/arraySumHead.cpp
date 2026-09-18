int arraySum(int array[], int n) {
    if (n == 0) {
        return 0;
    }

    return array[n - 1] + arraySum(array, n - 1);
}