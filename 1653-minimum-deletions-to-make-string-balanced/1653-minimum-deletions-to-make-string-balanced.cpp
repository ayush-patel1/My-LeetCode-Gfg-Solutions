class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int>pre(n),suf(n);
        pre[0]=s[0]=='b';
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+(s[i]=='b');
        }
        suf[n-1]=s[n-1]=='a';
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+(s[i]=='a');
        }
        int min_ans=n;
        for(int i=0;i<n;i++){
           min_ans=min(min_ans,suf[i]+pre[i]-1);
        }
        return min_ans;
    }
};