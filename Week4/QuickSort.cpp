#include "QuickSort.h"
#include <utility>

std::vector<int> QuickSort::sort(std::vector<int> list)
{
    if (!list.empty())
    {
        quickSort(list, 0, list.size() - 1);
    }

    return list;
}

void QuickSort::quickSort(std::vector<int>& list, int start, int end)
{
    // Base case: 0 or 1 elements
    if (start >= end)
    {
        return;
    }

    // Partition and get the pivot's final position
    int pivotIndex = partition(list, start, end);

    // Sort everything left of the pivot
    quickSort(list, start, pivotIndex - 1);

    // Sort everything right of the pivot
    quickSort(list, pivotIndex + 1, end);
}

int QuickSort::partition(std::vector<int>& list, int start, int end)
{
    int length = end - start + 1;

    int chosenPivotIndex;

    // Practical requirement:
    // if there are at least 3 elements,
    // choose the THIRD value in the current sublist
    if (length >= 3)
    {
        chosenPivotIndex = start + 2;
    }
    else
    {
        // No third value exists, so use the last value
        chosenPivotIndex = end;
    }

    int pivot = list[chosenPivotIndex];

    // Move the chosen pivot to the end temporarily
    std::swap(list[chosenPivotIndex], list[end]);

    int pivotIndex = start;

    // Move values smaller than the pivot to the left
    for (int i = start; i < end; i++)
    {
        if (list[i] < pivot)
        {
            std::swap(list[i], list[pivotIndex]);
            pivotIndex++;
        }
    }

    // Put the pivot into its final position
    std::swap(list[pivotIndex], list[end]);

    return pivotIndex;
}