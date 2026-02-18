class Solution {
public:
    bool hasAlternatingBits(int n) {
        string res="";
        for(int i=0;i<=31;i++){
            if(n&(1<<i)){
                res+="1";
            }else res+="0";
        }
        while(!res.empty() && res.back()=='0') res.pop_back();
        reverse(res.begin(),res.end());
        for(int i=0;i+1<res.size();i++){
            if(res[i]==res[i+1]) return false;
        }
        return true;
    }
};