#ifndef STANDARD_SORT_HPP
#define STANDARD_SORT_HPP
#include <algorithm>
#include <vector>
#include <chrono>

int standardSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    std::sort(nums.begin(), nums.end());

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    int middle = nums.size() / 2;
    return nums[middle-1];
}
#endif
