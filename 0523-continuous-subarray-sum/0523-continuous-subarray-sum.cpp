class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int cur=0; mp[0]=-1;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            int rem=cur%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2) return true;
            }
            if(mp.find(rem)==mp.end()){
                mp[rem]=i;
            }
        }
        return false;
    }
};