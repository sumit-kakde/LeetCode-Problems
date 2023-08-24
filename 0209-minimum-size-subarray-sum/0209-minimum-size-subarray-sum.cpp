class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int n = nums.size();
    int minLength = n + 1; // Initialize with a value greater than the possible length
    
    int left = 0, right = 0;
    int sum = 0;
    
    while (right < n) {
        sum += nums[right];
        
        while (sum >= target) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }
        
        right++;
    }
    
    return minLength == n + 1 ? 0 : minLength;
    }
};