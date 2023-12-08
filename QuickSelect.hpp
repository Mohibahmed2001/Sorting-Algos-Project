#ifndef QUICK_SELECT_HPP
#define QUICK_SELECT_HPP

#include <vector>
#include <chrono>
#include <random>
int quickSelect ( std::vector<int>& nums, int& duration );
std::vector<int>::iterator hoarePartition ( std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high );
   // hoarePartition precondition: low points to the first element in the subarray to be partitioned. The pivot is the last element in the subarray to be partitioned, and is pointed to by high.
   // hoarePartition returns an iterator to the pivot after it's placed.
   void insertionSort(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high);

#endif
