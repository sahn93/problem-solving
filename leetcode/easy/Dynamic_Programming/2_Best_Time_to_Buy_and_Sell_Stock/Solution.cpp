class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==0)
            return 0;
        int leftmin = prices[0];
        int maxprofit = 0;
        for (int i=1; i<prices.size(); i++) {
            if (leftmin > prices[i]) {
                leftmin = prices[i];
            }
            int profit = prices[i] - leftmin;
            if (profit > maxprofit)
                maxprofit = profit;
        }
        return maxprofit;
    }
}
