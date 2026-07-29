class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur=0;
        int n=nums.size();
        int mx=-1e9;
        for(int i=0;i<n;i++){
            cur+=nums[i];
            mx=max(mx,cur);;
            if(cur<0){
                cur=0;
            }
        }
        return mx;
    }
};