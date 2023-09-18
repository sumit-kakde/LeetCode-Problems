class Solution {
public:

    int maximum(vector<int>& nums){
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
    
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
    bool Sum(vector<int>& nums, int threshold, int div  ){
            int res=0;
            for(int i=0;i<nums.size();i++){
                res+=ceil((double)nums[i]/(double)div);
            }
             //res+=(double)nums[i]/(double)div;
            return res<=threshold;
           // return res;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans;
        if(nums.size()>threshold){
            return -1;
        }
            int low=1;
            int high=maximum(nums);
            while(low<=high){
                int mid=low+(high-low)/2;
                if(Sum(nums,threshold,mid)){
                    ans=mid;
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
        return ans;
    }
};