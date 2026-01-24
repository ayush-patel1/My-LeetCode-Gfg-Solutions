class Solution {
public:
    int minPairSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int max_ans=0;
       for(int i=0;i<n;i++){
         max_ans=max(max_ans,nums[i]+nums[n-i-1]);
       }
       return max_ans;
    }
};