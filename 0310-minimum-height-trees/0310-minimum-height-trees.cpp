class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0}; 

        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);
        vector<int> res;

        for(auto &e:edges){
            int u=e[0], v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++; 
            deg[v]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==1){
                q.push(i);
            }
        }

        while(n > 2){
            int sz = q.size();
            n -= sz;

            for(int i=0;i<sz;i++){
                int node = q.front();
                q.pop();

                for(auto &v:adj[node]){
                    deg[v]--;
                    if(deg[v] == 1){
                        q.push(v);
                    }
                }
            }
        }

        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }

        return res;
    }
};