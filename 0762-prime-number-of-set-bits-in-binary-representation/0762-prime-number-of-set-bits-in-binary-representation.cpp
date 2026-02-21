class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int mx = 20;
        vector<bool> p(mx + 1, true);
        p[0] = p[1] = false;
        for(int i = 2; i * i <= mx; i++){
            if(p[i]){
                for(int j = i * i; j <= mx; j += i)
                    p[j] = false;
            }
        }
        
        int ans = 0;
        for(int i = left; i <= right; i++){
            int c = __builtin_popcount(i);
            if(p[c]) ans++;
        }
        return ans;
    }
};