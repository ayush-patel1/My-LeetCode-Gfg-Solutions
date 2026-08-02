class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int e=0,o=0;
            for(int j=i;j<n;j++){
                if(nums[j]&1) o++;
                else e++;
                if(o>0 && e*b<=o*a) ans++;
            }
        }
        return ans;
    }
};