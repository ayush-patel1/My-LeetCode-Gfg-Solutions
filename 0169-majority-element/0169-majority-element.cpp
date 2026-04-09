class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cur=-1,cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cur=nums[i];
                cnt=1;
            }else{
                if(nums[i]==cur) cnt++;
                else cnt--;
            }
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cur) cnt++;
        }
        if(cnt>n/2) return cur;
        return -1;
    }
};