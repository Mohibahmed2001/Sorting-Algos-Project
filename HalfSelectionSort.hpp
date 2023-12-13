#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP

#include <iostream>
#include <vector>
#include <chrono>

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    if (nums.size() > 50000) {
        std::cout << "Size to big nered" << std::endl;
        return -1; 
    }
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i < (nums.size() / 2); ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(nums[i], nums[minIndex]);
    }
    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    size_t middleIndex = nums.size() / 2;

    // Need to determine if even or odd CRUCIAL STEP
    if (nums.size() % 2 == 0) {
        return (nums[middleIndex - 1]);
    } else {
        // ODD
        return nums[middleIndex];
    }
}

#endif
