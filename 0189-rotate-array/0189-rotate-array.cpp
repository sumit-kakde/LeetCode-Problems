class Solution {
public:
  void  rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k = k %n;
         reverse(nums, 0, n - 1); // Corrected this line
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
         //return nums;
    }
    void reverse(vector<int>& nums, int l,int h){
        while(l<h){
            swap(nums[l],nums[h]);
            l++;
            h--;
        }
    }
};