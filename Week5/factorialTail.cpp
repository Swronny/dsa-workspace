int factorialTail(int n, int total = 1) {
    if (n == 1) {
        return total;
    }

    return factorialTail(n - 1, total * n);
}