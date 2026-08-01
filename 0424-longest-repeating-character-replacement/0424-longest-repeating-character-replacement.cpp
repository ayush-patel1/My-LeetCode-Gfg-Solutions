class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0,r=0;
        int mxf=0;
        int mx=0;
        unordered_map<char,int>mp;
        while(r<n){
            mp[s[r]]++;
            mxf=max(mxf,mp[s[r]]);
            int w=r-l+1;
            while(l<=r && w-mxf>k){
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
                w=r-l+1;
            }
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};