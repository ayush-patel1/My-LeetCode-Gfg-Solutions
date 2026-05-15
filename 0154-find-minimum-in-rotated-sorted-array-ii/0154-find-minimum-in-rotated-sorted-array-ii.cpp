class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        int mn=1e9;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]==nums[mid] && nums[mid]==nums[r]){
                mn=min(nums[l],mn);
                l++; r--;
            }
            else if(nums[l]<=nums[mid]){
                mn=min(nums[l],mn);
                l=mid+1;
            }else{
                mn=min(mn,nums[mid]);
                r=mid-1;
            }
        }
        return mn;
    }
};