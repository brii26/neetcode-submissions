class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int b_idx = 0;
        int s_idx = 0;
        int profit = 0;
        for (int i = 1 ;i < n ; i++){
            if (prices[i] < prices[b_idx]) {
                b_idx = i;
            } else {
                int temp_profit = prices[i] - prices[b_idx];
                if (temp_profit > profit) {
                    profit = temp_profit;
                    s_idx = i;
                }
            }
        }
        return profit;
    }
};
