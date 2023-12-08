#ifndef WORST_CASE_QUICK_SELECT_HPP
#define WORST_CASE_QUICK_SELECT_HPP

#include <vector>

std::vector<int> worstCaseQuickSelect() {
    // Generate a worst-case input for quickselect with median-of-3 partitioning
    std::vector<int> worstCaseInput;

    for (int i = 1; i <= 20000; ++i) {
        worstCaseInput.push_back(i);
    }

    return worstCaseInput;
}

#endif // WORST_CASE_QUICK_SELECT_HPP
