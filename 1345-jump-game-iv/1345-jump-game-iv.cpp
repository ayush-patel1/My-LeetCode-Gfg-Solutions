class Solution {
public:
    int minJumps(vector<int>& arr) {
       int n=arr.size();

       unordered_map<int,vector<int>>mp;

       for(int i=0;i<n;i++){
          mp[arr[i]].push_back(i);
       }

       vector<vector<int>>adj(n);

       for(int i=0;i<n;i++){

            if(i+1<n) adj[i].push_back(i+1);

            if(i-1>=0) adj[i].push_back(i-1);
       }

       queue<pair<int,int>>q;

       vector<int>vis(n,0);
       unordered_map<int,int>done;

       q.push({0,0});

       vis[0]=1;

       while(!q.empty()){

            auto [u,d]=q.front();

            q.pop();

            if(u==n-1) return d;

            for(auto &v:adj[u]){

                if(!vis[v]){

                    vis[v]=1;

                    q.push({v,d+1});
                }
            }

            if(done[arr[u]]) continue;

            done[arr[u]]=1;

            for(auto &v:mp[arr[u]]){

                if(!vis[v]){

                    vis[v]=1;

                    q.push({v,d+1});
                }
            }
       }

       return -1;
    }
};