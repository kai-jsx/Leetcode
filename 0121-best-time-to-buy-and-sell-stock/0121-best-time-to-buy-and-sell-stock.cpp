class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())  return 0;
        int minPrice = prices[0], maxProfit = 0;
        for (int i = 1; i < prices.size(); i++){
            minPrice = min(prices[i], minPrice);

            maxProfit = max(maxProfit,prices[i]-minPrice);
        }
        return(maxProfit);
    }
};