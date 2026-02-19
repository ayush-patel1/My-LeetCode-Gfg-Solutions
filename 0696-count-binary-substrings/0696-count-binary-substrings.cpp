class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans=0;
        int cnt=1,b=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]) cnt++;
            else{
                ans+=min(b,cnt);
                b=cnt;
                cnt=1;
            }
        }
        return ans+min(b,cnt);
    }
};