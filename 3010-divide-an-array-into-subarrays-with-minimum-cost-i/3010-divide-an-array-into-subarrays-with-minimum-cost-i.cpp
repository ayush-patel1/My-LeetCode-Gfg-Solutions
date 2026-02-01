class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int sum=nums[0];  //phela element to include krna hi hoga, uske baad minmum and second minimum ka sum;
        int min=INT_MAX;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<min){
                min=nums[i];
                ans=i;
            }
        } 
        sum+=min;
        min=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<min && i!=ans){
                min=nums[i];
            }

        }
        sum+=min;
    return sum;    
    }
};