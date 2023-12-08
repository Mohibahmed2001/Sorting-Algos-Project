#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>
#include <algorithm>
#include <chrono>

template <typename winner>
void recursiveMergeSort(winner begin, winner end);

int mergeSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();
    recursiveMergeSort(nums.begin(), nums.end());
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    return nums[nums.size() / 2];
}

template <typename winner>
void recursiveMergeSort(winner begin, winner end) {
    if (end - begin > 1) {
        winner middle = begin + (end - begin) / 2;
        recursiveMergeSort(begin, middle);
        recursiveMergeSort(middle, end);
        std::vector<int> temp(std::distance(begin, end));
        std::merge(begin, middle, middle, end, temp.begin());
        std::copy(temp.begin(), temp.end(), begin);
    }
}

#endif  // MERGESORT_HPP
