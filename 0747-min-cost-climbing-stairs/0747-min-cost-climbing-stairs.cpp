class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        if (n <= 1) {
            return 0; // If there are 0 or 1 steps, the cost is 0.
        }

        std::vector<int> dp(n, 0);
        
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + std::min(dp[i-1], dp[i-2]);
        }

        // The minimum cost to reach the top is in the last or second to last element.
        return std::min(dp[n - 1], dp[n - 2]);
    }
};