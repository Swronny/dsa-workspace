int arraySumIterative(int array[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += array[i];
    }

    return total;
}