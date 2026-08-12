class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int maxLen=0;
        unordered_map<int,int>mp;
        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp[nums[right]]>k){
                    mp[nums[left]]--;
                    left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};