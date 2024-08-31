class Solution {
public:
    int solve(vector<int>&nums,int k){
            int count=0;
        int len=0;
        unordered_map<int,int>mp;
        int left=0;
        int right=0;
        while(right<nums.size()){
            mp[nums[right]]++;
            while(mp.size()>k && left<=right){
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
                count+=right-left+1;;
                
            
           right++; 
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       int ans1=solve(nums,k);
       int ans2=solve(nums,k-1);
       return abs(ans1-ans2);
    }
};