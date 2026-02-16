class Solution {
public:
    int reverseBits(int n) {
        string res="";
        for(int i=0;i<32;i++){
           if(n & (1u<<i)) res+='1';
           else res+='0';
        }
        reverse(res.begin(),res.end());
        unsigned int ans=0;
        for(int i=0;i<32;i++){
           if(res[i]=='1'){
            ans += (1u<<i);
           }
        }
        return ans;
    }
};
