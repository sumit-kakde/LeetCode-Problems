class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> inDegree(n, 0);
        vector<vector<int>> adj(n);
        vector<int> dp(n, 0);
        
        // Build the adjacency list and in-degrees
        for (const auto& relation : relations) {
            int prevCourse = relation[0] - 1;
            int nextCourse = relation[1] - 1;
            adj[prevCourse].push_back(nextCourse);
            inDegree[nextCourse]++;
        }
        
        queue<int> q;
        
        // Initialize the queue with courses that have no prerequisites
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        int result = 0;
        
        while (!q.empty()) {
            int currCourse = q.front();
            q.pop();
            
            // Update the time required to complete the current course
            dp[currCourse] += time[currCourse];
            
            // Update the result with the maximum time for courses that lead to the current course
            result = max(result, dp[currCourse]);
            
            // Process the next courses
            for (int nextCourse : adj[currCourse]) {
                inDegree[nextCourse]--;
                if (inDegree[nextCourse] == 0) {
                    q.push(nextCourse);
                }
                dp[nextCourse] = max(dp[nextCourse], dp[currCourse]);
            }
        }
        
        return result;
    }
};