class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1, -1);
        
        for (int i=1; i<=amount; i++) {
            for (int coin: coins) {
                if (coin > i) continue;
                if (coin == i) {
                    dp[i] = 1;   
                    break;
                }
                if (dp[i-coin] != -1) {
                    if (dp[i] == -1)
                        dp[i] = dp[i-coin] + 1;
                    else
                        dp[i] = min(dp[i], dp[i-coin] + 1);
                }
            }
        }
        
        return dp[amount];
    }
};
