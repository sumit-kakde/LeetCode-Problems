class Solution { 
public: 
    vector<int> searchRange(vector<int>& nums, int target) { 
        auto lb = std::lower_bound(nums.begin(), nums.end(), target); 
        auto ub = std::upper_bound(nums.begin(), nums.end(), target); 
        if (lb != nums.end() && *lb == target) { 
            int first = std::distance(nums.begin(), lb); 
            int last = std::distance(nums.begin(), ub) - 1; 
            return {first, last}; 
        } else  return {-1, -1}; 
    } 
};