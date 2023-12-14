#ifndef QUICKSELECT_HPP
#define QUICKSELECT_HPP
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<int>::iterator medianOfThree(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    std::vector<int>::iterator middle = low + (high - low) / 2;
    if (*low > *middle) {
        std::iter_swap(low, middle);
    }
    if (*low > *high) {
        std::iter_swap(low, high);
    }
    if (*middle > *high) {
        std::iter_swap(middle, high);
    }

    return middle;
}

std::vector<int>::iterator hoarePartition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    std::vector<int>::iterator pivot = medianOfThree(nums, low, high);
    std::iter_swap(pivot, high);
    pivot = high;
    auto i = low - 1;
    for (auto j = low; j < high; ++j) {
        if (*j < *pivot) {
            ++i;
            std::iter_swap(i, j);
        }
    }
    std::iter_swap(i + 1, high);
    return i + 1;
}

int quickSelectRecursive(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int& duration) {
    if (high - low + 1 > 10) {
        auto pivot = hoarePartition(nums, low, high);
        if (pivot > low) {
            quickSelectRecursive(nums, low, pivot - 1, duration);
        }
        if (pivot < high) {
            quickSelectRecursive(nums, pivot + 1, high, duration);
        }
    } else {
        std::sort(low, high + 1);
    }
    auto medianIndex = low + (high - low) / 2;
    return *medianIndex;
}

int quickSelect(std::vector<int>& nums, int& duration) {
    auto low = nums.begin();
    auto high = nums.end() - 1;
    //CORRECT RETURN
    return quickSelectRecursive(nums, low, high, duration);
}

#endif