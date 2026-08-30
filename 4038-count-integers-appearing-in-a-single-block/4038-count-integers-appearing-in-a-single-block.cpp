class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        vector<int>first(101,-1),last(101,n);
        for(int i=0;i<n;i++){
            if(first[nums[i]]==-1) first[nums[i]]=i;
            last[nums[i]]=i;
        }
        for(int i=1;i<=100;i++){
            if(first[i]==-1) continue;
            bool flg=true;
            for(int j=first[i];j<=last[i];j++){
                if(nums[j]!=i){
                    flg=false;
                    break;
                }
            }
            if(flg) cnt++;
        }
        return cnt;
    }
};