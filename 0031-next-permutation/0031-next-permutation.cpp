class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int b_idx=-1;
        int n=nums.size();
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                b_idx=i;
                break;
            }
        }
        if(b_idx==-1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1;i>b_idx;i--){
               if(nums[i]>nums[b_idx]){
                swap(nums[i],nums[b_idx]);
                break;
               }
            }
            reverse(nums.begin()+b_idx+1,nums.end());
        }
        return;
    }
};