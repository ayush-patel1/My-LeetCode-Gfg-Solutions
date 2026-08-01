class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int>mp;
       int n=s.size();
       int l=0,r=0;
       int mx=0;
       while(r<n){
          mp[s[r]]++;
          while(l<=r && mp[s[r]]>1){
             mp[s[l]]--;
             if(mp[s[l]]==0) mp.erase(s[l]);
             l++;;
          }
          mx=max(mx,r-l+1);
          r++;;
       } 
       return mx;
    }
};