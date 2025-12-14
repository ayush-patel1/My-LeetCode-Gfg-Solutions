class Solution {
public:
#define ll long long
    long long minMoves(vector<int>& balance) {
        ll n = balance.size();
        ll sum = 0;
        int neg = -1;

        for(int i = 0; i < n; i++){
            sum += balance[i];
            if(balance[i] < 0) neg = i;
        }

        if(sum < 0) return -1;
        if(neg == -1) return 0;

        ll need = -balance[neg];
        vector<pair<int,int>> v;

        for(int i = 0; i < n; i++){
            if(i == neg || balance[i] <= 0) continue;

            int d = abs(i - neg);
            d = min(d, (int)n - d);
            v.push_back({d, balance[i]});
        }

        sort(v.begin(), v.end());

        ll ans = 0;
        for(auto &p : v){
            if(need == 0) break;
            ll take = min((ll)p.second, need);
            ans += take * p.first;
            need -= take;
        }

        return ans;
    }
};
