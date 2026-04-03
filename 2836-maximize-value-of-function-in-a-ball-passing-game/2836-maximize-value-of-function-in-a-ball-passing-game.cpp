class Solution {
public:
    #define ll long long
    
    long long getMaxFunctionValue(vector<int>& r, long long k) {
        int n = r.size();
        
        vector<vector<int>> up(n, vector<int>(35));
        vector<vector<ll>> sum(n, vector<ll>(35));
        
        for(int i = 0; i < n; i++){
            up[i][0] = r[i];
            sum[i][0] = r[i];
        }
        
        for(int j = 1; j < 35; j++){
            for(int i = 0; i < n; i++){
                up[i][j] = up[up[i][j-1]][j-1];
                sum[i][j] = sum[i][j-1] + sum[up[i][j-1]][j-1];
            }
        }
        
        ll ans = 0;
        
        for(int i = 0; i < n; i++){
            ll cur = i;
            ll res = i;
            
            for(int j = 0; j < 35; j++){
                if(k & (1LL << j)){
                    res += sum[cur][j];
                    cur = up[cur][j];
                }
            }
            
            ans = max(ans, res);
        }
        
        return ans;
    }
};

//we can apply binary lifting here as pattern is somewhat like that
//also contrainsts are heavy