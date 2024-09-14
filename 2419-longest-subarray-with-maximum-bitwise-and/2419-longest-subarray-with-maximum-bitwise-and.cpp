class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val=*max_element(nums.begin(),nums.end());
        int max_len=0;
        int curr_len=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==max_val){
                curr_len++;
            }
            else{
                curr_len=0;
            }
            max_len=max(curr_len,max_len);
        }
        return max_len;
    }
};