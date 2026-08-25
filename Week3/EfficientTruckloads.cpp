// EfficientTruckloads.cpp

#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {

    // Create the memo table on the first call.
    //
    // memo[i] stores the number of trucks required
    // for a pile containing i crates.
    //
    // -1 means "we haven't calculated this yet".
    if (memo.empty()) {
        memo.resize(10001, -1);
    }

    // BASE CASE:
    // This pile already fits on one truck.
    if (numCrates <= loadSize) {
        return 1;
    }

    // MEMOISATION:
    // If this problem has already been solved,
    // don't recursively calculate it again.
    if (memo[numCrates] != -1) {
        return memo[numCrates];
    }

    // Divide the pile into two smaller piles.
    int left = numCrates / 2;

    // Subtraction handles odd numbers:
    // 7 -> left = 3, right = 4
    int right = numCrates - left;

    // Recursively solve the two smaller problems.
    int leftTrucks = numTrucks(left, loadSize);
    int rightTrucks = numTrucks(right, loadSize);

    // Combine their answers.
    int totalTrucks = leftTrucks + rightTrucks;

    // IMPORTANT:
    // Save the answer before returning it.
    // If we encounter this pile size again,
    // we can immediately retrieve this result.
    memo[numCrates] = totalTrucks;

    return totalTrucks;
}