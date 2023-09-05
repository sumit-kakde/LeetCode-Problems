class Solution {
public:
    int findMin(vector<int>& nums) {
        int res=INT_MAX;
        int low=0;
        int high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
           if(nums[low]<=nums[high]){
               res=min( nums[low],res);
               break;
           }else if (nums[low]<=nums[mid]){
               res=min(res,nums[low]);
                low=mid+1;
            }else{
                 res=min(res,nums[mid]);
                high=mid-1;
            
            }
        }
        return res;
    }
};