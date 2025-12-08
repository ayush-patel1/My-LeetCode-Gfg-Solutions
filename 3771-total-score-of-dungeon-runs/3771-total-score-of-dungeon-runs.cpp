class Solution {
public:
    #define ll long long
    long long totalScore(int hp, vector<int>& d, vector<int>& r) {
        int n = d.size();
        vector<ll> p(n,0);
        p[0] = d[0];
        for(ll i=1;i<n;i++) p[i] = p[i-1] + d[i];

        ll ans = 0;
        for(ll i=0;i<n;i++){
            ll ind = lower_bound(p.begin(),p.end(),p[i]+r[i]-hp)-p.begin();
            if(ind == 0){
                if(hp-p[i]>=r[i]) ind--;
            }
            ans += max(0*1LL,i-ind);

        }
        return ans;
    }
};