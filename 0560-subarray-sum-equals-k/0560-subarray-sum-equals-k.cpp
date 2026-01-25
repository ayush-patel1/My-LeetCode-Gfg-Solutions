class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cur=0; int ans=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
           cur+=nums[i];
           int rem=cur-k;
           if(cur==k) ans++;
           if(mp.find(rem)!=mp.end()){
              ans+=mp[rem];
           }
           mp[cur]++;
        }
        return ans;
    }
};