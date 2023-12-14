#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP

#include <vector>
#include <chrono>
#include <algorithm>

void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
    std::vector<int>::size_type child;
    int tmp = std::move(heap[hole]);

    while (hole * 2 + 1 < heap.size()) {
        child = hole * 2 + 1;
        if (child != heap.size() - 1 && heap[child + 1] > heap[child]) {
            ++child;
        }
        if (heap[child] > tmp) {
            heap[hole] = std::move(heap[child]);
        } else {
            break;
        }
        hole = child;
    }

    heap[hole] = std::move(tmp);
}

void buildHeap(std::vector<int>& heap) {
    for (int i = heap.size() / 2 - 1; i >= 0; --i) {
        percDown(heap, i);
    }
}

int halfHeapSort(std::vector<int>& nums, int& duration) {
    auto start = std::chrono::high_resolution_clock::now();

    if (nums.size() < 2) {
        duration = 0;
        return (nums.size() == 1) ? nums[0] : 0; // Return 0 for an empty vector
    }

    // Move the first element to the end of the vector
    std::swap(nums[0], nums[nums.size() - 1]);

    // Build the max heap
    buildHeap(nums);

    // Remove n/2 elements from the heap
    for (std::vector<int>::size_type i = nums.size() / 2; i > 0; --i) {
        std::swap(nums[0], nums[i - 1]);
        percDown(nums, 0);
    }

    auto end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // The median is now at the root of the remaining max heap
    return nums[0];


#endif
