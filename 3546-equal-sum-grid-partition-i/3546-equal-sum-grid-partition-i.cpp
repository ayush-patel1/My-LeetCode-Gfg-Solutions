class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        long long tot=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) tot+=grid[i][j];
        }

        unordered_map<int, vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[grid[i][j]].push_back({i,j});
            }
        }

        long long sum=0;

        // row cut
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) sum+=grid[i][j];

            if(i+1<n){
                if(2*sum==tot) return true;

                long long diff=abs(tot-2*sum);

                if(mp.count(diff)){
                    for(auto &p:mp[diff]){
                        int r=p.first,c=p.second;
                        if(r!=0 && r!=n-1 && c!=0 && c!=m-1){
                            return true;
                        }
                    }
                }
            }
        }

        sum=0;

        // col cut
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++) sum+=grid[i][j];

            if(j+1<m){
                if(2*sum==tot) return true;

                long long diff=abs(tot-2*sum);

                if(mp.count(diff)){
                    for(auto &p:mp[diff]){
                        int r=p.first,c=p.second;
                        if(r!=0 && r!=n-1 && c!=0 && c!=m-1){
                            return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};