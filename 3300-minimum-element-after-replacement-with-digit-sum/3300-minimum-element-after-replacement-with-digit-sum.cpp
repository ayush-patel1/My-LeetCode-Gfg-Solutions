class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int sum_of_dig=0;
            while(nums[i]>0){
               sum_of_dig+=nums[i]%10;
                nums[i]/=10;
            }
            mini=min(mini,sum_of_dig);
        }
        return mini;
    }
};