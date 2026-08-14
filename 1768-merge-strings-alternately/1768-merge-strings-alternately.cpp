class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        int n=word1.size(),m=word2.size();
        string res="";
        while(i<n && j<m){
            if(i<=j) res+=word1[i++];
            else res+=word2[j++];
        }
        while(i<n) res+=word1[i++];
        while(j<m) res+=word2[j++];
        return res;
    }
};