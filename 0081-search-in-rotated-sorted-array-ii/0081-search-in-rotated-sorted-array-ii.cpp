class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low <=high){
            int mid=low +(high-low)/2;
            if(nums[mid]==target)return true;
            if (nums[low]==nums[mid] && nums[mid]==nums[high]) {
                low++;
                high--;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else {
            // Right half is sorted
            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1; // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }

        }
        return false;
    }
};