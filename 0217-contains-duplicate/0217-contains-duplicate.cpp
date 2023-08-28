class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        multiset<int >mt;
        for(int i=0;i<nums.size();i++){
            mt.insert(nums[i]);
        }
           for (auto it:mt) {
            if(mt.count(it)>=2)
          return true;
    }
    return false;
    }
};