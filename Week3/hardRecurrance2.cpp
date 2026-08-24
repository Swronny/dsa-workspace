// Write a tail recursive function to compute:
// f(n) = 1 x 2 + 2 x 3 + 3 x 4 + … + (n-1) x n

int multSum(int n, int sum = 0) {
    if (n == 0) {
        return 0;
    }

    return multSum(n - 1, sum += n * (n - 1));
}

// Correct
int multSum(int n, int sum = 0) {
    if (n == 0) {
        return sum;
    }

    return multSum(n - 1, sum + n * (n - 1));
}