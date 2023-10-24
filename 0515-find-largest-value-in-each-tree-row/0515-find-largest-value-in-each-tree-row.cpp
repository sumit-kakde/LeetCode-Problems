class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        
        if (!root) {
            return result;
        }
        
        queue<TreeNode*> levelQueue;
        levelQueue.push(root);
        
        while (!levelQueue.empty()) {
            int levelSize = levelQueue.size();
            int levelMax = INT_MIN; // Initialize the maximum value for this level.
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = levelQueue.front();
                levelQueue.pop();
                levelMax = max(levelMax, current->val);
                
                if (current->left) {
                    levelQueue.push(current->left);
                }
                
                if (current->right) {
                    levelQueue.push(current->right);
                }
            }
            
            result.push_back(levelMax);
        }
        
        return result;
    }
};