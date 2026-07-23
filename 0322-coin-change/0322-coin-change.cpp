class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount < 0)
            return INT_MAX;
        if (dp[amount] != -1) {
            return dp[amount];
        }
        int ans = INT_MAX;
        for (auto coin : coins) {
            if (solve(coins, amount - coin, dp) < INT_MAX) {
                ans = min(ans, solve(coins, amount - coin, dp) + 1);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        // unvisited marks -1;
        vector<int> dp(10001, -1);
        dp[0]=0;
        for (auto coin : coins) {
            if(coin<amount)
            dp[coin] = 1;
        }
        return solve(coins,amount,dp)==INT_MAX?-1:solve(coins,amount,dp);
    }
};