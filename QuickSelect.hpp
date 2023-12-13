#ifndef QUICK_SELECT_HPP
#define QUICK_SELECT_HPP
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    // Pivot 3 method
    auto pivotIt = low + (high - low) / 2;
    std::iter_swap(pivotIt, high);
    int pivot = *high;
    auto i = low - 1;
    for (auto j = low; j < high; ++j) {
        if (*j <= pivot) {
            ++i;
            std::iter_swap(i, j);
        }
    }
    std::iter_swap(i + 1, high);
    return i + 1;
}

void insertionSort(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    for (auto i = low + 1; i <= high; ++i) {
        int key = *i;
        auto j = i - 1;

        while (j >= low && *j > key) {
            *(j + 1) = *j;
            --j;
        }

        *(j + 1) = key;
    }
}

int quickSelect(std::vector<int>& nums, int& duration) {
    auto start_time = std::chrono::high_resolution_clock::now();
    if (nums.size() <= 10) {
        insertionSort(nums, nums.begin(), nums.end() - 1);
    } else {
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(0, nums.size() - 1);
        auto low = nums.begin();
        auto high = nums.end() - 1;
        auto targetIndex = nums.size() / 2;
        while (low <= high) {
            auto pivot = hoarePartition(nums, low, high);
            if (pivot == nums.begin() + targetIndex) {
                break;
            } else if (pivot < nums.begin() + targetIndex) {
                low = pivot + 1;
            } else {
                high = pivot - 1;
            }
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    return *(nums.begin() + nums.size() / 2);
}

#endif
