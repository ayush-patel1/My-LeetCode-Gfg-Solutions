class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>arr;
        for(auto it:st){
            arr.push_back(it);
        }
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
              idx=i;
                break;
            }
        }
        if(idx==-1) return 1;
        int check_counter=1;
        int ans=0;
        for(int i=idx;i<n;i++){
            if(arr[i]!=check_counter){
               ans=check_counter; 
                break;
            }
            check_counter++;
        }
        if(ans==0) return arr.back()+1;
        return ans;
    }
};