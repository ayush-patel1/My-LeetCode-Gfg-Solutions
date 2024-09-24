class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2){
        int maxi=0;
        unordered_map<string,int>mp;
        for(auto it:arr1){
            string temp=to_string(it);
            string curr="";
            for(int i=0;i<temp.size();i++){
                curr+=temp[i];
                mp[curr]=i+1;
            }
        }
        for(auto it:arr2){
            string temp=to_string(it);
            string curr="";
            for(int i=0;i<temp.size();i++){
                curr+=temp[i];
                if(mp.find(curr)!=mp.end()){
                    maxi=max(maxi,mp[curr]);
                }
            }
        }
        return maxi;
    }
};