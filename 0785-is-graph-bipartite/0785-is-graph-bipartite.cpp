class Solution {
public:
    // Helper function to perform DFS and color the graph
    bool dfs(int curr, vector<int>& color, vector<vector<int>>& graph) {
        for (int e : graph[curr]) {
            if (color[e] == 0) { // If the node is not colored
                color[e] = color[curr] == 1 ? 2 : 1; // Assign opposite color to adjacent node
                if (!dfs(e, color, graph)) { // Recursively DFS
                    return false;
                }
            } else if (color[curr] == color[e]) { // If adjacent node has the same color
                return false;
            }
        }
        return true;
    }

    // Main function to check if the graph is bipartite
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // Initialize color array, 0 means not colored

        // Iterate over all nodes in the graph
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) { // If the node is not colored
                color[i] = 1; // Start coloring the node with color 1
                if (!dfs(i, color, graph)) { // If DFS finds the graph is not bipartite
                    return false;
                }
            }
        }
        return true; // The graph is bipartite
    }
};
