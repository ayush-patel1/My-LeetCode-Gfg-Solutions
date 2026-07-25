class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int m=s.size();
        int mx=0;
        for(int i=0;i<m;i++){
           for(int j=i+1;j<m;j++){
              mx=max(mx,(s[i]-'0')*(s[j]-'0'));
           }
        }
        return mx;
    }
};