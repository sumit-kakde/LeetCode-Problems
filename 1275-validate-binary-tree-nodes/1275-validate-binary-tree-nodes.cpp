class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, false);
        vector<int> inDegree(n, 0);

        // Count the in-degrees for each node.
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                if (inDegree[leftChild[i]] > 1) {
                    return false; // More than one incoming edge to a node.
                }
            }
            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                if (inDegree[rightChild[i]] > 1) {
                    return false; // More than one incoming edge to a node.
                }
            }
        }

        // Find the root node (a valid binary tree has exactly one root).
        int root = -1;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                if (root != -1) {
                    return false; // Multiple potential root nodes.
                }
                root = i;
            }
        }

        if (root == -1) {
            return false; // No root node found.
        }

        // Perform a depth-first traversal to check connectivity.
        if (!dfs(root, leftChild, rightChild, visited, n)) {
            return false;
        }

        // Check if all nodes have been visited.
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }

private:
    bool dfs(int node, vector<int>& leftChild, vector<int>& rightChild, vector<bool>& visited, int n) {
        if (node == -1) {
            return true;
        }

        if (visited[node]) {
            return false; // Detected a cycle.
        }

        visited[node] = true;

        return dfs(leftChild[node], leftChild, rightChild, visited, n) && 
               dfs(rightChild[node], leftChild, rightChild, visited, n);
    }
};