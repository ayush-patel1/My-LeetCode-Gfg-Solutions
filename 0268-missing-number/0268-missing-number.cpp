class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int xr1=0,xr2=0;
        for(int i=0;i<n;i++){
           xr1=xr1^i;
           xr2=xr2^nums[i];
        }
        xr1=xr1^n;
        return xr1^xr2;
    }
};