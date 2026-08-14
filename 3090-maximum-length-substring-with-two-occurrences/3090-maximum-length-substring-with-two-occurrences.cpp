class Solution {
public:
bool check(string s){
    unordered_map<char,int>mp;
    for(auto &ch:s) mp[ch]++;
    for(auto &it:mp){
        if(it.second>2) return false;
    }
    return true;
}
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int mx=0;
        for(int i=0;i<n;i++){
            string tmp="";
            for(int j=i;j<n;j++){
                tmp+=s[j];
                if(check(tmp)){
                   mx=max(mx,int(tmp.size()));
                }
            }
        }
        return mx;
    }
};