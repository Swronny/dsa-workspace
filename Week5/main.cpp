#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Count occurence of each digit
// std::vector<int>& numbers, not numbers as we we want to modify
void countingSort(std::vector<int>& numbers, int exp) {
  // {0, 0, 0, ...}
  int count[10] = {0};

  for (int i = 0; i < numbers.size(); i++) {
    int digit = (numbers[i] / exp) % 10;  // 15312 / 100 = 153 % 10 = 3 (get 3)
    count[digit]++;
  }

  // Convert to cumulative counts
  for (int i = 1; i < 10; i++) {
    count[i] = count[i] + count[i - 1];
  }

  // Sort output
  std::vector<int> output(numbers.size());
  for (int i = numbers.size() - 1; i >= 0; i--) {
    // Extract digit
    int digit = (numbers[i] / exp) % 10;

    // Place digit in its COUNT position, e.g if num = 5, corresponds to a 7 in
    // count, place in 7-1
    output[count[digit] - 1] = numbers[i];

    // Decrement EXTRACTED DIGIT not i
    count[digit]--;
  }

  // Replace nums
  for (int i = 0; i < numbers.size(); i++) {
    numbers[i] = output[i];
  }
}

//
void radixSort(std::vector<int>& numbers) {
  // Find max place
  int max = numbers[0];

  for (int i = 1; i < numbers.size(); i++) {
    if (numbers[i] > max) {
      max = numbers[i];
    }
  }

  // Repeat countingSort calls for amount of exponents of max
  for (int exp = 1; max / exp > 0; exp *= 10) {
    countingSort(numbers, exp);
  }
}

int main() {
  std::string line;
  // Read the entire input line
  if (!std::getline(std::cin, line)) {
    return 0;
  }
  std::stringstream ss(line);
  std::string token;

  // Convert input to
  // e.g "1, 3, 762, 92" -> individual integer elements
  std::vector<int> numbers;

  while (std::getline(ss, token, ',')) {
    numbers.push_back(std::stoi(token));
  }

  // Sort
  radixSort(numbers);

  // Print comma-separated result
  for (int i = 0; i < numbers.size(); i++) {
    if (i > 0) {
      std::cout << ",";
    }

    std::cout << numbers[i];
  }

  return 0;
}