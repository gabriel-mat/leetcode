/*
Let's start with a brute-force approach. We can use nested loops to check every possible combination of buying and selling days. 
The outer loop selects the buy day, and the inner loop checks all future days to sell. 
We calculate the profit for each pair and update our max_profit variable, which is initialized to 0. 
This approach gives us an O(N2) time complexity and O(1) space complexity.

entrevistador pede melhoria:
I think we need to keep track of two variables as we iterate: 
the current_max_profit and the minimum price seen so far (our buying price).


I'll initialize max_profit to 0 and min_price to values[0].
we iterate through the array, and for each price, we do two checks: 
first, if the current price is less than min_price, we update min_price. 
Otherwise, we calculate the current profit (the current price minus min_price). 
If this profit is greater than max_profit, we update it. 
This brings the time complexity down to O(N) while keeping space at O(1).
*/

class Solution{
  public:
    int maxProfit(vector<int> &prices){
        int max_profit = 0, min_price = prices[0];

        for (int price : prices) {
            min_price = std::min(min_price, price);
            max_profit = std::max(max_profit, price - min_price);
        }

        return max_profit;
      }
  };
