#include <iostream>
#include <vector>
#include <algorithm> // for std::min and std::max

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> res;

        int current = 0;

        while(current < intervals.size() && intervals[current][1] < newInterval[0]){
            res.push_back(intervals[current]);
            current++;
        }

        if(current == intervals.size()){
            res.push_back(newInterval);
            return res;
        }

        if(intervals[current][0] > newInterval[1])
            res.push_back(newInterval);
        else{
            int l = std::min(intervals[current][0], newInterval[0]);
            int r = std::max(intervals[current][1], newInterval[1]);

            current++;
            while(current < intervals.size() && intervals[current][0] <= r){
                r = std::max(r, intervals[current++][1]);
            }
            res.push_back({l, r});
        }

        while(current < intervals.size())
            res.push_back(intervals[current++]);
        return res;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
    std::vector<int> newInterval = {2, 5};

    std::vector<std::vector<int>> result = sol.insert(intervals, newInterval);

    std::cout << "Merged intervals: ";
    for (const auto& interval : result) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
}
