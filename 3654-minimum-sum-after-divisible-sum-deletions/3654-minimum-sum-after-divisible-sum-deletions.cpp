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
        unordered_map<int,int> mp;

        mp[0] = -1;  // base case

        for(int i = 0; i < n; i++){
            int rem = pre[i] % k;
            dp[i] = (i > 0 ? dp[i-1] : 0);

            if(mp.find(rem) != mp.end()){
                int j = mp[rem];
                
                ll sub = pre[i] - (j == -1 ? 0 : pre[j]);
                ll prev = (j == -1 ? 0 : dp[j]);
                
                dp[i] = max(dp[i], prev + sub);
            }

            // update best j
            if(mp.find(rem) == mp.end()){
                mp[rem] = i;
            } else {
                int j = mp[rem];
                
                ll prev = (j == -1 ? 0 : dp[j]) - (j == -1 ? 0 : pre[j]);
                ll cur = dp[i] - pre[i];
                
                if(cur > prev){
                    mp[rem] = i;
                }
            }
        }

        return tot - dp[n-1];
    }
};