#ifndef INPLACEMERGESORT_HPP
#define INPLACEMERGESORT_HPP

#include <vector>
#include <chrono>

template <typename loser>
void recursiveInPlaceMergeSort(loser begin, loser end);

int inplacemergeSort(std::vector<int>& nums, int& duration);

#endif
