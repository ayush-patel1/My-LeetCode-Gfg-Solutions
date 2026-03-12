class Solution {
public:
bool check(int d,vector<int>&nums,int t){
    int sum=0;
    for(auto &it:nums){
        sum+=(it+d-1)/d;
        if(sum>t) return false;
    }
    return true;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,nums,threshold)){
                ans=mid;
                r=mid-1;
            }else l=mid+1;
        }
        return ans;
    }
};