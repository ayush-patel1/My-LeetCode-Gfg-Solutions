class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ac=count(s.begin(),s.end(),'1');
        int n=s.size();
        vector<int>c;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int st=i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                c.push_back(i-st);
            }else i++;
        }
        int mx=0;
        for(int i=1;i<c.size();i++){
            mx=max(mx,c[i]+c[i-1]);
        }
        return mx+ac;
    }
};