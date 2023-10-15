class Solution {
    public int numWays(int steps, int arrLen) {
        int mod = 1000000007;
        
        // Calculate the maximum number of steps that you can take and still be within the array
        int maxSteps = Math.min(steps / 2, arrLen - 1);
        
        // Create a 2D array to store the number of ways to reach each position at each step
        int[][] dp = new int[maxSteps + 1][steps + 1];
        
        // Initialize the base case
        dp[0][0] = 1;
        
        for (int step = 1; step <= steps; step++) {
            for (int position = 0; position <= maxSteps; position++) {
                dp[position][step] = dp[position][step - 1];
                if (position > 0) {
                    dp[position][step] = (dp[position][step] + dp[position - 1][step - 1]) % mod;
                }
                if (position < maxSteps) {
                    dp[position][step] = (dp[position][step] + dp[position + 1][step - 1]) % mod;
                }
            }
        }
        
        return dp[0][steps];
    }
}
