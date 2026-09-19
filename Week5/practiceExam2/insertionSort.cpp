#include <vector>
#include <algorithm>

void insertionSort(std::vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        for (int j = i; j >= 0; j--) {
            if (array.at(j) < array.at(j-1)) {
                std::swap(array[j], array[j-1]);
            }

            else break;
        }
    }
}

void insertionSortFix(std::vector<int>& array) {
    for (int i = 1; i < array.size(); i++) {

        for (int j = i; j > 0; j--) {

            if (array.at(j) < array.at(j - 1)) {
                std::swap(array[j], array[j - 1]);
            }
            else {
                break;
            }
        }
    }
}