#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP

#include <vector>
#include <chrono>
#include <algorithm>

template <typename RandomAccessIterator>
void recursiveInPlaceMergeSort(RandomAccessIterator begin, RandomAccessIterator end) {
    if (end - begin > 1) {
        RandomAccessIterator middle = begin + (end - begin) / 2;
        recursiveInPlaceMergeSort(begin, middle);
        recursiveInPlaceMergeSort(middle, end);
        std::inplace_merge(begin, middle, end);
    }
}

int inPlaceMergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();
    recursiveInPlaceMergeSort(nums.begin(), nums.end());
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    if (nums.size() % 2 == 0) {
        return nums[(nums.size() / 2) - 1];
    } else {
        return nums[nums.size() / 2];
    }
}

template void recursiveInPlaceMergeSort(std::vector<int>::iterator begin, std::vector<int>::iterator end);

#endif
