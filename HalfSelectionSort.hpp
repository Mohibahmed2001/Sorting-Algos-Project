#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP
using namespace std;
#include <iostream>
#include <vector>
#include <chrono>

int halfSelectionSort(std::vector<int>& nums, int& duration) {
   auto start = std::chrono::high_resolution_clock::now();
  if (nums.size() > 50000) {
    std::cout << "List size exceeds 50,000. This function cannot handle large lists." << std::endl;
    return -1;
  }
if(nums.size()%2!=0){
  for (int i = 0; i < nums.size() / 2; ++i) {
    int min_index = i;
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[j] < nums[min_index]) {
        min_index = j;
      }
    }
    std::swap(nums[i], nums[min_index]);
  }
   auto end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  return nums[(nums.size()/2)];
}else{
    for (int i = 0; i < (nums.size() / 2)-1; ++i) {
    int min_index = i;
    for (int j = i + 1; j < nums.size(); ++j) {
      if (nums[j] < nums[min_index]) {
        min_index = j;
      }
    }
    std::swap(nums[i], nums[min_index]);
  }
   auto end = std::chrono::high_resolution_clock::now();
  duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  return nums[(nums.size()/2)-1];
}
 

#endif
