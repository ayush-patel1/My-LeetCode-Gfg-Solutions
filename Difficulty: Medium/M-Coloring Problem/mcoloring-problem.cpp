//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isSafe(int col, vector<vector<int>>& adj, int node, vector<int>& color) {
        for (auto it : adj[node]) {
            if (color[it] == col) {
                return false;
            }
        }
        return true;
    }
    
    bool solve(int v, vector<vector<int>>& adj, vector<int>& color, int m) {
        for (int i = 0; i < v; i++) {
            if (color[i] == 0) {
                for (int k = 1; k <= m; k++) {
                    if (isSafe(k, adj, i, color)) {
                        color[i] = k;
                        if (solve(v, adj, color, m)) return true;
                        color[i] = 0;
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
        vector<vector<int>> adj(v);
        for (const auto& edge : edges) {
            int u = edge.first;
            int v = edge.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> color(v, 0);
        return solve(v, adj, color, m);
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m;
        cin >> n;
        cin.ignore(); // Ignore newline after reading n
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Populate the array with edge values
        }
        cin >> m;
        cin.ignore(); // Ignore newline after reading m

        int edges_count = arr.size();
        vector<pair<int, int>> edges(edges_count /
                                     2); // Correct size of the edges vector

        for (int i = 0; i < edges_count; i += 2) {
            int l1 = arr[i];
            int l2 = arr[i + 1];
            edges[i / 2] = {l1, l2}; // Properly assign the pair
        }

        Solution ob;
        cout << (ob.graphColoring(n, edges, m) ? "true" : "false")
             << endl; // Call the graph coloring function
    }
    return 0;
}

// } Driver Code Ends