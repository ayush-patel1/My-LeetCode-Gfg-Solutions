class Solution {
public:
#define ll long long
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        ll cur=0,ans=0;
        for(int i=0;i<n;i++){
           if(nums[i]>=minK && nums[i]<=maxK){
              cur++;
           }else{
              ans+=1LL*cur*(cur+1)/2;
              cur=0;
           }
        }
        ans+=1LL*cur*(cur+1)/2;
        return ans;
    }
};