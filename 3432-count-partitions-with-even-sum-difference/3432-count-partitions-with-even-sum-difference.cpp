class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size(); 
        int res=0;  int tot_sum=accumulate(nums.begin(),nums.end(),0);
        int curr_sum=0;
        for(int i=0;i<n-1;i++){
            curr_sum+=nums[i];
            if((tot_sum-2*curr_sum)%2==0){
                res++;
            }
        }
        return res;
    }
};