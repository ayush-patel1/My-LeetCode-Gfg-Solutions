class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        long long curr=0;
        long long minSum=INT_MAX;
        int total=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            minSum=min(minSum,curr);
            if(curr>0){
                curr=0;
            }
        }
        curr=0;
        long long maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            maxSum=max(curr,maxSum);
            if(curr<0){
                curr=0;
            }
        }
        if(maxSum<0){
            return maxSum;
        }
        return max(total-minSum,maxSum);
    }
};