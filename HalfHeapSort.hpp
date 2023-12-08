#ifndef HALFHEAPSORT_HPP
#define HALFHEAPSORT_HPP
#include <chrono>

#include <vector>

int halfHeapSort(std::vector<int>& nums, int& duration);

void percDown(std::vector<int>& heap, std::vector<int>::size_type hole);

void buildHeap(std::vector<int>& heap);
int halfHeapSort(std::vector<int>& nums, int& duration) {
  // Move first element to the back, leaving index 0 empty as per textbook.
  std::swap(nums[0], nums.back());

  // Start timer.
  auto startTime = std::chrono::steady_clock::now();

  // Build the heap.
  buildHeap(nums);

  // Remove elements from the heap and maintain heap condition.
  for (int i = nums.size() - 1; i >= nums.size() / 2; --i) {
    // Swap the root (largest element) with the last element in the heap.
    std::swap(nums[0], nums[i]);

    // Decrease the size of the heap.
    nums.pop_back();

    // Restore the heap property by percolating down the first element.
    percDown(nums, 0);
  }

  // Stop timer and calculate duration.
  auto endTime = std::chrono::steady_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

  return 0;
}

void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
  // Get the left child index.
  size_t leftChild = 2 * hole + 1;

  // Get the right child index.
  size_t rightChild = 2 * hole + 2;

  // Find the largest child index.
  size_t largestChild = leftChild;
  if (rightChild < heap.size() && heap[rightChild] > heap[leftChild]) {
    largestChild = rightChild;
  }

  // If the hole is smaller than the largest child, swap them and continue percolating down.
  if (largestChild < heap.size() && heap[largestChild] > heap[hole]) {
    std::swap(heap[largestChild], heap[hole]);
    percDown(heap, largestChild);
  }
}

void buildHeap(std::vector<int>& heap) {
  // Start from the middle element and percolate down each element.
  for (int i = heap.size() / 2 - 1; i >= 0; --i) {
    percDown(heap, i);
  }
}
#endif