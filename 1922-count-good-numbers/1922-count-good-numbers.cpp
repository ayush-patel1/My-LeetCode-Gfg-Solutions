class Solution {
public:
    const int mod = 1e9 + 7;

    int expo(int x, long long n) {
        int ans = 1;
        while(n > 0) {
            if(n & 1) {
                ans = (1LL * ans * x) % mod;
                n = n - 1;
            } else {
                x = (1LL * x * x) % mod;
                n = n / 2;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2;
        long long odd = n / 2;
        int odd_ans = expo(4, odd);
        int even_ans = expo(5, even);
        return (1LL * odd_ans * even_ans) % mod;
    }
};