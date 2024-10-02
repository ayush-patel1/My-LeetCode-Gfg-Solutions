class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
         int n=arr.size();
        vector<int>rank(n);
        unordered_map<int,int>mp;
        int rank_counter=1;
        vector<int>dup_arr=arr;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(mp.find(arr[i])!=mp.end()) continue;
            mp[arr[i]]=rank_counter;
            rank_counter++;
        }
        for(int i=0;i<n;i++){
            rank[i]=mp[dup_arr[i]];
        }
        return rank;
    }
};