class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int ans=nums.size();
    int right = nums.size()-1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] >= target) {
            right = mid - 1;

            ans=mid; // Search in the right half
        } else {
            left = mid+1; // Search in the left half
        }
    }

    return ans; // Insertion position found
    }
};