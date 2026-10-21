class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1,0);
        vector<int>dp(n+1,0);
        for(auto it:relations){
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        for(int i=1;i<=n;i++){
          if(indegree[i]==0){
            q.push(i);
            dp[i]=time[i-1];
          }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                dp[it]=max(dp[it],time[it-1]+dp[node]);
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};