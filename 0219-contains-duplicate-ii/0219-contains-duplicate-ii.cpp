class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    std::unordered_map<int, int> indexMap; // Map of element to its index
    
    for (int i = 0; i < nums.size(); ++i) {
        if (indexMap.find(nums[i]) != indexMap.end() && i - indexMap[nums[i]] <= k) {
            return true; // Found a pair with the condition satisfied
        }
        indexMap[nums[i]] = i; // Update index for the element
    }
    
    return false; // No pair with the condition found
    }
};