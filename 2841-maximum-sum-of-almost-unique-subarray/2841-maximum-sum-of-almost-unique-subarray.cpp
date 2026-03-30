class Solution {
public:
#define ll long long
    long long maxSum(vector<int>& nums, int m, int k) {
        int n=nums.size();
        ll max_sum=0;
        int l=0,r=0;
        unordered_map<int,int>mp;
        ll cur=0;
        while(r<n){
           mp[nums[r]]++;
           cur+=nums[r];
           while(l<=r && r-l+1>k){
             mp[nums[l]]--;
             cur-=nums[l];
             if(mp[nums[l]]==0){
                mp.erase(nums[l]);
             }
             l++;
           }
           if(r-l+1==k && mp.size()>=m){
              max_sum=max(1LL*max_sum,cur);
           }
           r++;
        }
        return max_sum;
    }
};