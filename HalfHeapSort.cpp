#include "HalfHeapSort.hpp"
#include <chrono>
#include <vector>
int halfHeapSort(std::vector<int>& nums, int& duration) {
  int first = nums[0];
  nums[0] = nums[nums.size() - 1];
  nums[nums.size() - 1] = first;
  nums.pop_back();
  auto start = std::chrono::high_resolution_clock::now();
  buildHeap(nums);
  for (size_t i = 0; i < nums.size() / 2; ++i) {
    std::swap(nums[0], nums[nums.size() - 1]);
    nums.pop_back();
    percDown(nums, 0);
  }
  auto end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  return nums[0];
}

void percDown(std::vector<int>& heap, std::vector<int>::size_type hole) {
  while (2 * hole + 1 < heap.size()) {
    size_t child = 2 * hole + 1;
    if (child + 1 < heap.size() && heap[child] < heap[child + 1]) {
      child++;
    }
    if (heap[hole] >= heap[child]) {
      break;
    }

    std::swap(heap[hole], heap[child]);
    hole = child;
  }
}

void buildHeap(std::vector<int>& heap) {
  for (int i = heap.size() / 2 - 1; i >= 0; --i) {
    percDown(heap, i);
  }
}
