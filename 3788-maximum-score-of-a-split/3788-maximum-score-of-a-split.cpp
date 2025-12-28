class Solution {
public:
#define ll long long
    long long maximumScore(vector<int>& nums) {
        int n=nums.size();
        vector<ll>pre(n),suff_min(n);
        pre[0]=nums[0],suff_min[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--){
            suff_min[i]=min(suff_min[i+1],1LL*nums[i]);
        }
        ll ans=-1e18;
        for(int i=0;i<n-1;i++){
          ans=max(ans,pre[i]-suff_min[i+1]);
        }
        return ans;
    }
};