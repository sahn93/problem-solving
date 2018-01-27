class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==0)
            return 0;
        bool hold = false;
        int cost, earning = 0;
        for (int i=0; i<prices.size()-1; i++) {
            if (!hold) {
                if (prices[i] < prices[i+1]) {
                    hold = true;
                    cost = prices[i];
                }
            } else {
                if (prices[i] > prices[i+1]) {
                    hold = false;
                    earning += prices[i] - cost;
                }
            }
        }
        if (hold)
            earning += (prices.back() - cost);
        return earning;    
    }
};
