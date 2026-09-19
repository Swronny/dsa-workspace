#include <vector>
#include <algorithm>

// Increment i, j nested
// For each i, j iterates and find minimum and swap with i if found.
// Each i prefix is already sorted
int main() {
  std::vector<int> array = {1, 6, 7};

  for (int i = 0; i < array.size(); i++) {
    int minIndex = i;

    for (int j = i + 1; j < array.size(); j++) {
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }

    std::swap(array[minIndex], array[i]);
  }

  return 0;
}