class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(auto &num:nums){
            mp[num]++;
           if(mp[num]>k) continue;
           res.push_back(num);
        }
        return res;
    }
};