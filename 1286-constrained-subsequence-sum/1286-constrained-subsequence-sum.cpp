class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        deque<pair<int, int>> dq; // (sum, index)
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front().second < i - k) {
                dq.pop_front(); // Remove elements out of the k window
            }

            int prevMax = dq.empty() ? 0 : dq.front().first;
            dp[i] = max(prevMax, 0) + nums[i];
            maxSum = max(maxSum, dp[i]);

            while (!dq.empty() && dp[i] >= dq.back().first) {
                dq.pop_back(); // Remove elements that are less than the current dp value
            }

            dq.push_back({dp[i], i});
        }

        return maxSum;
    }
};