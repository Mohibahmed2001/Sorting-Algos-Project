#ifndef HALFSELECTIONSORT_HPP
#define HALFSELECTIONSORT_HPP
#include<vector>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;

int halfSelectionSort ( std::vector<int>& nums, int& duration ){
    auto start = std::chrono::steady_clock::now();
    int midpoint = (nums.size()+1)/2; 
    for(int i = 0; i < midpoint; ++i){
        auto minit = nums.begin() + i; 
        for(auto j = nums.begin()+i+1; j != nums.end(); ++j){ 
            if(*j<*minit) minit = j; 
        }
        std::iter_swap(nums.begin()+i, minit); 
    }
    auto end = std::chrono::steady_clock::now();
    auto time = end-start;
    duration = time.count();

    return nums[midpoint-1];

}




#endif
