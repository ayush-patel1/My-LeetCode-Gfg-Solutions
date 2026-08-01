class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        int ones=0,zeros=0;
        int mx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) zeros++;
            else ones++;
            while(l<=i && zeros>k){
                if(nums[l]==0) zeros--;
                else ones--;
                l++;
            }
            mx=max(mx,i-l+1);
        }
        return mx;
    }
};