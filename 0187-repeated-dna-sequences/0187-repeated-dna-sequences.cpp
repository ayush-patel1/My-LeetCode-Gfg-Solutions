class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        int  n=s.size();
        int left=0;
        int right=0;
        string t="";
        while(right<n){
            t+=s[right];
            while(t.size()>10 && left<=right){
                left++;
                t=t.substr(1);
            }
            if(t.size()==10){
                    mp[t]++;
            }
            right++;
        }
        vector<string>ans;
        for(auto it:mp){
            if(it.second>1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};