// Write a tail recursive function that implements x^n (i.e. 2^3 = 2 * 2 * 2)

int powers(int base, int power, int total = 1) { // Change init total to 1
    if (base == 0 || power == 0) { // return total
        return total;
    }

    return(base, power - 1, total * base); // * base added 
}