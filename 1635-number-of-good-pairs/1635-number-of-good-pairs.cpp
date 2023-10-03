class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> frequency; 
        int count = 0; 
        for (int num : nums) frequency[num]++; 
        for (auto it = frequency.begin(); it != frequency.end(); ++it) { 
            int n = it->second; 
            if (n > 1) count += (n * (n - 1)) / 2; 
        } 
        return count;   
    }
};