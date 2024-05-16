#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if(intervals.size() == 1)
            return intervals;

        std::vector<std::vector<int>> result;
        std::sort(intervals.begin(), intervals.end());

        result.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            if(result.back()[1] >= intervals[i][0])
                result.back()[1] = std::max(result.back()[1], intervals[i][1]);
            else{
                result.push_back(intervals[i]);
            }
        }

        return result; 
    }
};

int main() {
    Solution solution;

    // Example usage
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    std::vector<std::vector<int>> merged_intervals = solution.merge(intervals);

    std::cout << "Merged intervals:" << std::endl;
    for (const auto& interval : merged_intervals) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
