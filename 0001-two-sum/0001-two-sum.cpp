class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
    
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }

            sort(v.begin(),v.end());
        while(l<r){
            int cur=v[l].first+v[r].first;
            if(cur==target){
                return {v[l].second,v[r].second};
            }else if(cur>target){
                r--;
            }else l++;
        }
        return {-1,-1};
    }

};