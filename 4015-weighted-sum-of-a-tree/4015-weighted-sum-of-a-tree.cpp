class Solution {
public:
#define ll long long
vector<int>d;
vector<vector<int>>adj;
void solve(int node,int par,int de){
    d[node]=de;
    for(auto &it:adj[node]){
        if(it==par) continue;
        solve(it,node,de+1);
    }
}

    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n=parent.size();
        adj.resize(n);
        d.assign(n,0);
        for(int i=0;i<n;i++){
            if(parent[i]==-1) continue;
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        solve(0,-1,0);
        int h=*max_element(d.begin(),d.end());
        ll res=0;
        for(int i=0;i<n;i++){
           res+=1LL*nums[i]*(h-d[i]+1);
        }
        return res;
    }
};