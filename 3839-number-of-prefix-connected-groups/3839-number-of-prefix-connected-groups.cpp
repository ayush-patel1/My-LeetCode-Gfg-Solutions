class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mp;
        for(auto &word:words){
           if(word.size()>=k)  mp[word.substr(0,k)]++;
        }
        int max_grp=0;
        for(auto &it:mp){
            if(it.second>=2) max_grp++;
        }
        return max_grp;
    }
};