// Write a tail recursive function to sum the digits in an integer (i.e. 362
// would return 11 i.e. 3+6+2 )
#include <vector>

int sumDigits(int num, int sum = 0) {
    if (num == 0) {
        return sum;
    }

    return sumDigits(num / 10, sum + num % 10);
}

// Old
int sumDigits(int num, int sum = 0) {
  if (num == 0) {
    return 0;
  }

  std::vector<int> digits;

  while (num > 10) {
    digits.push_back(num % 10); // Extract last
    num /= 10; // Remove last
  }

  // Reverse
  std::vector<int> digitsReversed;
  for (int i = digits.size(); i > 0; i--) {
    digitsReversed.push_back(digits[i - 1]);
  }

  for (int i = 0; i < digitsReversed.size(); i++) {
    sum += digitsReversed[i];
  }

  digitsReversed.pop_back();

  return sumDigits(0, sum);
}