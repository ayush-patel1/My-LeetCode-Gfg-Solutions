#define ll long long
class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        int n=nums.size();
        ll cnt=0;
        unordered_map<int,ll>mpp;
        mpp[0]=1;
        int xr=0;
        for(auto it:nums){
           xr=xr^it;
           cnt+=mpp[xr];
           mpp[xr]++;
        }
        return cnt;
    }
};