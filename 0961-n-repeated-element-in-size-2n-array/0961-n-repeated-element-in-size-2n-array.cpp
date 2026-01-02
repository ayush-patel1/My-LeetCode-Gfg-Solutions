class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size()/2;
        unordered_map<int,int>mp;
        for(auto &e:nums) mp[e]++;
        for(auto &it:mp){
            if(it.second==n){
                return it.first;
            }
        }
        return -1;
    }
};