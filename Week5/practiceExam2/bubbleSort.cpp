#include <algorithm>
#include <vector>

void bubbleSort(std::vector<int>& array) {
  for (int i = array.size() - 1; i > 1; i++) {
    for (int j = 0; j < i; j++) {
      if (array[j+1] < array[j]) {
        std::swap(array[j+1], array[j]);
      }
    }
  }
}
