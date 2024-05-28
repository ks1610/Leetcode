/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let prof = 0;
    let buy = prices[0];
    for(let i = 0; i < prices.length; i++){
        if (buy < prices[i])
            prof += prices[i] - buy;
        buy = prices[i];
    }
    return prof;
};

// Test the function with a sample input
let prices = [7, 1, 5, 3, 6, 4];

console.log("Stock prices:", prices);

let maxProfitValue = maxProfit(prices);

console.log("Maximum profit:", maxProfitValue);
