#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP

#include <vector>
#include <chrono>
#include <algorithm>
// hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
// hoarePartition returns an iterator to the pivot after it's placed.
//Note that this implementation of hoarePartition makes it usable with different pivot selection methods, but also requires that you select your pivot and swap it into the last position prior to calling hoarePartition.
std::vector<int>::iterator medianOf3(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    std::vector<int>::iterator mid = low + (high - low) / 2;
    if (*low > *mid)
        std::swap(*low, *mid);
    if (*low > *high)
        std::swap(*low, *high);
    if (*mid > *high)
        std::swap(*mid, *high);

    return mid;
}
std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    auto pivotIt = medianOf3(nums, low, high);
    int pivot = *pivotIt;
    std::swap(*pivotIt, *(high - 1));

    auto i = low - 1;
    auto j = high - 1;

    while (true) {
        do {
            ++i;
        } while (*i < pivot);

        do {
            --j;
        } while (*j > pivot);

        if (i >= j)
            break;

        std::swap(*i, *j);
    }

    std::swap(*i, *(high - 1)); 
    return i;
}

void quickSelectRecursive(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    if (high - low > 10) {
        auto pivotIt = hoarePartition(nums, low, high);
        quickSelectRecursive(nums, low, pivotIt);
        quickSelectRecursive(nums, pivotIt + 1, high);
    } else {
        std::sort(low, high);
    }
}

int quickSelect(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    quickSelectRecursive(nums, nums.begin(), nums.end());

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    return nums[nums.size() / 2];
}

#endif