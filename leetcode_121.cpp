
// 贪心 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(auto price : prices) {
            minPrice = min(price, minPrice);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

// 动态规划 
//dp[i][0] 表示第 i 天持有股票
//dp[i][1] 表示第 i 天不持有股票 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(2));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); i++) {
        	//dp[i][0] 要么保持前一天持有的状态，要么就今天持有 
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            //dp[i][1] 要么保持前一天不持有的状态，要么今天卖出 
            dp[i][1] = max(dp[i-1][1], prices[i] + dp[i-1][0]);
        }

        return dp[len-1][1];
    }
};
