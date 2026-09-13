#include "BubbleSort.h"

std::vector<int> BubbleSort::sort(std::vector<int> list) {
    for (int i = 0; i < list.size(); i++) {
        for (int j = i+1; i < list.size(); i++) {
            if (list[i] > list[j]) {
                int temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    return list;
}