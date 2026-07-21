class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int max_len=1; int cur_len=1;
        if(n==0) return 0;
        for(int i=1;i<n;i++){
            if(nums[i-1]==nums[i]) continue;
           if(nums[i-1]==nums[i]-1){
              cur_len++;
              cout<<cur_len;
           }else{
              cur_len=1;
           }
           max_len=max(cur_len,max_len);
        }
        return max_len;
    }
};