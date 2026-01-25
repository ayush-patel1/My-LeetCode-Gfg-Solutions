class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]<=nums[i]){
                return i+1;
            }
        }
        return 0;
    }
};