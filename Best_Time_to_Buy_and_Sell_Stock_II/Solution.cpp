#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];

        for (int i = 0; i < prices.size(); i++) {
            if (buy < prices[i]) {
                profit += prices[i] - buy;
            }    
            buy = prices[i];
        }
        return profit;
    }
};

int main() {
    Solution solution;
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};

    std::cout << "Stock prices: ";
    for (int price : prices) {
        std::cout << price << " ";
    }
    std::cout << std::endl;

    int maxProfit = solution.maxProfit(prices);

    std::cout << "Maximum profit: " << maxProfit << std::endl;

    return 0;
}
