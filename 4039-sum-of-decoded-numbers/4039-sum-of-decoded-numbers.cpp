class Solution {
public:
    const int mod = 1e9 + 7;

    int func(long long x, long long y) {
        long long ans = 1;

        while (y) {
            if (y & 1) {
                ans = (ans * x) % mod;
                y--;
            } else {
                x = (x * x) % mod;
                y /= 2;
            }
        }

        return ans;
    }

    int sumDecoded(vector<long long>& nums) {
        long long ans = 0;

        for (auto &it : nums) {
            long long num = it;
            int w = num % 10;

            string s = to_string(num);
            s.pop_back();

            string x = s.substr(0, w);
            string y = s.substr(w);

            ans = (ans + func(stoll(x), stoll(y))) % mod;
        }

        return ans;
    }
};