class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        multiset<int > st;
        int sum=0;
       // int sum2=0;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
            //sum2+=nums[i];
        }
          for (auto it:st) {
            if(st.count(it)==1)
            sum+=it;
        
    }
        return sum;
    }
};