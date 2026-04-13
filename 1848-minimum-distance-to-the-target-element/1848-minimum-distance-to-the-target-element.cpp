class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n=nums.size();
        int dis=1e9;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                dis=min(dis,abs(i-start));
            }
        }
        return dis;
    }
};