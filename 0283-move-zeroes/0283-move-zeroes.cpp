class Solution {
public:
    void moveZeroes(vector<int>& nums) {
             int nonZeroIndex = 0;

    // Move non-zero elements to the beginning
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != 0) {
            nums[nonZeroIndex++] = nums[i];
        }
    }

    // Fill the rest of the array with zeroes
    while (nonZeroIndex < nums.size()) {
        nums[nonZeroIndex++] = 0;
    }
    }
};