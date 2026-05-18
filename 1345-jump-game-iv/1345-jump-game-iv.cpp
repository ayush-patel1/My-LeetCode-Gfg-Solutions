class Solution {
public:
    int minJumps(vector<int>& arr) {
       int n=arr.size();

       unordered_map<int,vector<int>>mp;

       for(int i=0;i<n;i++){
          mp[arr[i]].push_back(i);
       }

       queue<pair<int,int>>q;

       vector<int>vis(n,0);

       q.push({0,0});

       vis[0]=1;

       while(!q.empty()){

            auto [u,d]=q.front();

            q.pop();

            if(u==n-1) return d;

            if(u+1<n && !vis[u+1]){
                vis[u+1]=1;
                q.push({u+1,d+1});
            }

            if(u-1>=0 && !vis[u-1]){
                vis[u-1]=1;
                q.push({u-1,d+1});
            }

            for(auto &v:mp[arr[u]]){

                if(!vis[v]){

                    vis[v]=1;

                    q.push({v,d+1});
                }
            }

            mp[arr[u]].clear();
       }

       return -1;
    }
};