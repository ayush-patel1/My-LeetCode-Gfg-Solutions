class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n=nums.size();

        for(int i=0;i<n;i++){

            bool flg=true;

            for(int j=i+1;j<i+n;j++){

                if(nums[(j-1)%n]>nums[j%n]){
                    flg=false;
                    break;
                }
            }

            if(flg) return true;
        }

        return false;
    }
};