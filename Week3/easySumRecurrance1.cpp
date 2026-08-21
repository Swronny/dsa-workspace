// Write a tail recursive function to sum the integers from 1 to n

int sum(int n, int total = 0) {
    if (n == 0) {
        return 0;
    }

    return sum(n - 1, total + n);
}