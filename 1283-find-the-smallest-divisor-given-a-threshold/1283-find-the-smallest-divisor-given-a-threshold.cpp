class Solution {
public:
bool check(int mid,vector<int>&nums,int t){
    int r=0;
    for(auto &it:nums){
        r+=(it+mid-1)/mid;
        if(r>t) return false;
    }
    return r<=t;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1,r=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,nums,threshold)){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};