class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            string temp="";
            for(int i=0;i<s.size();i++){
                temp+=((s[i]+1-'a')%25)+'a';
            }
            s+=temp;
        }
        return s[k-1];
    }
};