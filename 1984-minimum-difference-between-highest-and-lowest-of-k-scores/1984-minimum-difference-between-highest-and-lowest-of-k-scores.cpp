class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int min_dif=1e5;
        for(int i=0;i<n-k+1;i++){
            int max_n=0;
            int min_n=1e5;
            for(int j=i;j<min(i+k,n);j++){
               max_n=max(max_n,nums[j]);
               min_n=min(min_n,nums[j]);
            }
            min_dif=min(min_dif,max_n-min_n);
        }
        return min_dif;
    }
};