#include "WorstCaseQuickSelect.hpp"

std::vector<int> worstCaseQuickSelect() {
    std::vector<int> worstCase;
    worstCase.reserve(20000);

     // worstCaseQuickSelect generates a worst-case input for a quickselect that uses median-of-3 partitioning.
    //The input it generates must be of length 20,000, and contain each number from 1-20000 once.
    for (int i = 1; i <= 20000; ++i) {
        worstCase.push_back(i);
    }

    return worstCase;
}
