class Solution {
public:
    string reverseByType(string s) {
        string a="";
        string b="";
        for(auto &ch:s){
            if(isalpha(ch)){
                a+=ch;
            }else
                b+=ch;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i=0,j=0,k=0;
        string ans="";
        while((i<a.size() || j<b.size()) && k<s.size()){
            if(isalpha(s[k])){
                 ans+=a[i];
                i++;
            }
            else{
                 ans+=b[j];j++;
            }
            k++;
        }
        return ans;
    }
};