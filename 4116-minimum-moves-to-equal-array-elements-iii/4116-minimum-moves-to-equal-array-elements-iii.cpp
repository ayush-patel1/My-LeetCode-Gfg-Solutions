class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_elem=*max_element(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans+=abs(max_elem-nums[i]);
        }
        return ans;
    }
};