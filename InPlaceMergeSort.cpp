#include "InplacemergeSort.hpp"
#include <algorithm>

template <typename loser>
void recursiveInPlaceMergeSort(loser begin, loser end) {
    if (end - begin > 1) {
        loser middle = begin + (end - begin) / 2;
        recursiveInPlaceMergeSort(begin, middle);
        recursiveInPlaceMergeSort(middle, end);
        std::inplace_merge(begin, middle, end);
    }
}

int inplacemergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();
    recursiveInPlaceMergeSort(nums.begin(), nums.end());
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    return nums[nums.size() / 2];
}

// Explicit instantiation for the template function with the required types
template void recursiveInPlaceMergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);
