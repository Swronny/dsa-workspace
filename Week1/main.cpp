// COMP 2017 - Practical 1
//
// I declare this submission is my own work and has not been copied from any
// other source. Name: Ronan Anciano a#: a1971715
//

#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
  int n;
  std::cin >> n;   // read an integer from input stream
  std::cout << n;  // print the result to output stream

  std::vector<int> vector;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    vector.push_back(i);
  }

  // Starting time elapsed
  auto start = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < 1000; i++) {
    sum += vector[rand() % n];
  }

  auto end = std::chrono::high_resolution_clock::now();

  auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  double avg = static_cast<double>(elapsed.count()) / 1000.0;

  std::cout << avg;

  return 0;
}