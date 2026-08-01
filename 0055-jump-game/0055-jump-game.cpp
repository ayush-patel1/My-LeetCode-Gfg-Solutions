class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mx>=n-1) return true;
            if(mx==i && nums[i]==0) return false;
            mx=max(mx,nums[i]+i);
        }
        return false;
    }
};