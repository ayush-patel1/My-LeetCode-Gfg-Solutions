class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0;
        unordered_map<char,int>mp;
        int cnt=0;
        while(r<n){
            mp[s[r]]++;
            while(l<=r && mp.size()>=3){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                cnt+=n-r;
                l++;
            }
            r++;
        }
        return cnt;
    }
};
