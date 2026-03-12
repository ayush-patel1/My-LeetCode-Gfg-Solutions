class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int l=1,r=n-2;
        if(n==1) return 0;
        if(nums[n-2] < nums[n-1]) return n-1;
        if(nums[0] > nums[1]) return 0;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid-1] <= nums[mid] && nums[mid] >= nums[mid+1]){
                return mid;
            }
            else if(nums[mid] > nums[mid-1]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
};