#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP
using namespace std;
#include <iostream>
#include <vector>
#include <chrono>

int halfSelectionSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::steady_clock::now();
    if (nums.size() >= 50000) {
        std::cout << "Method too big, selection sort is not recommended." << std::endl;
        duration = -1;
        return 0;
    }
    int n = nums.size();
    int median = nums.size() / 2;
    for (int i = 0; i <= median; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] <= nums[min_index]) {
                min_index = j;
            }
        }
        std::swap(nums[i], nums[min_index]);
    }
    auto end = std::chrono::steady_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    return nums[median];
}

#endif
