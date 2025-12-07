class Solution {
public:
#define ll long long
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n = t1.size();
        vector<pair<int,int>> v;
        ll ans = 0;
        for(int i = 0; i < n; i++){
            v.push_back({t1[i] - t2[i], i});
        }
        sort(v.rbegin(), v.rend());
        vector<int> vis(n, 0);
        for(int i = 0; i < k; i++){
            ans += t1[v[i].second];
            vis[v[i].second] = 1;
        }
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                ans += max(t1[i], t2[i]);
            }
        }
        return ans;
    }
};
