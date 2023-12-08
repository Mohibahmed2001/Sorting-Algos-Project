#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <vector>
#include <chrono>

template <typename winner>
void recursiveMergeSort(winner begin, winner end);

int mergeSort(std::vector<int>& nums, int& duration);

#endif
