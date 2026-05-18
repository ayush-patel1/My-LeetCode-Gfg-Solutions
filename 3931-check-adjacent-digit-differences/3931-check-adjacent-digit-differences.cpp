class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        int n=s.size();
        for(int i=0;i+1<n;i++){
            int d1=s[i]-'0';
            int d2=s[i+1]-'0';
            if(abs(d1-d2)>2) return false;
        }
        return true;
    }
};