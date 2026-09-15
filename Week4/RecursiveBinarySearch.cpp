#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(std::vector<int> list, int target)
{
    return binarySearch(list, target, 0, list.size() - 1);
}

bool RecursiveBinarySearch::binarySearch(std::vector<int>& list, int target, int start, int end)
{
    // Base case: no elements left to search
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;

    // Target found
    if (list[mid] == target)
    {
        return true;
    }

    // Target must be on the left
    if (target < list[mid])
    {
        return binarySearch(list, target, start, mid - 1);
    }

    // Target must be on the right
    return binarySearch(list, target, mid + 1, end);
}