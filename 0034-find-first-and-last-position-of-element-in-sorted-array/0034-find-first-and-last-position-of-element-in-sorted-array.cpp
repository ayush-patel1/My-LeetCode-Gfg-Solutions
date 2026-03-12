class Solution {
public:
int solve(vector<int>&nums,int tar,char ch){
    int l=0,r=nums.size()-1;
    int ans=-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(nums[mid]==tar){
            ans=mid;
            if(ch=='f'){
                r=mid-1;
            }else l=mid+1;
        }else if(tar>nums[mid]){
            l=mid+1;
        }else r=mid-1;
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int a=solve(nums,target,'f');
        int b=solve(nums,target,'l');
        return {a,b};
    }
};