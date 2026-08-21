/* Write a tail recursive function to calculate greatest common divisor (GCD) of positive integers using
Euclid’s algorithm:
gcd(a, b) = gcd(b, a mod b) and gcd(a, 0) = a;
*/

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}