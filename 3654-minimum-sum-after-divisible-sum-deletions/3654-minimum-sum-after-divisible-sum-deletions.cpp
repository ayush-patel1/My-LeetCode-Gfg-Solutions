class Solution {
public:
#define ll long long

    long long minArraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<ll> pre(n);
        ll cur = 0, tot = 0;
        
        for(int i = 0; i < n; i++){
            cur += nums[i];
            pre[i] = cur;
            tot += nums[i];
        }
        
        vector<ll> dp(n, 0);
        unordered_map<int,ll> mp;
        
        mp[0] = 0;
        
        for(int i = 0; i < n; i++){
            int rem = pre[i] % k;
            if(rem < 0) rem += k;
            
            dp[i] = (i > 0 ? dp[i-1] : 0);
            
            if(mp.find(rem) != mp.end()){
                dp[i] = max(dp[i], mp[rem] + pre[i]);
                mp[rem] = max(mp[rem], dp[i] - pre[i]);
            } else {
                mp[rem] = dp[i] - pre[i];
            }
        }
        
        return tot - dp[n-1];
    }
};