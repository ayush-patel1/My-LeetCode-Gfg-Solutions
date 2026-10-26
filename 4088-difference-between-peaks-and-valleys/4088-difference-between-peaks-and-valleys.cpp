class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n=nums.size();
        int sp=0,sv=0;
        for(int i=1;i+1<n;i++){
            if(nums[i]>nums[i+1] && nums[i]>nums[i-1]) sp+=nums[i];
            if(nums[i]<nums[i+1] && nums[i]<nums[i-1]) sv+=nums[i];
        }
        return sp-sv;
    }
};