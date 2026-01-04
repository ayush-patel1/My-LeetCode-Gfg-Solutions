class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int>t;
            for(int j=1;j*j<=nums[i];j++){
               if(nums[i]%j==0){
                 t.insert(j);
                 t.insert(nums[i]/j);
               }
            }
            if(t.size()==4){
                res+=accumulate(t.begin(),t.end(),0);
            }
        }
        return res;
    }
};