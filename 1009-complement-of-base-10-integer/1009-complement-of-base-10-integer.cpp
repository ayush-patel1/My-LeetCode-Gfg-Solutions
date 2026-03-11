class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int bits=log2(n)+1;
        int ans=0;
        for(int i=0;i<bits;i++){
            if(!(n&(1<<i))) ans+=(1<<i);
        }
        return ans;
    }
};