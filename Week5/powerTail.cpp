int power(int x, int n, int total = 1) {
    if (n == 0) {
        return total;
    }

    return power(x, n - 1, total * x);
}