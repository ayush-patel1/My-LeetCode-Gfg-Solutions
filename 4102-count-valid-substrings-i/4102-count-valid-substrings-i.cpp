class Solution {
public:
    #define ll long long

    long long countValidSubstrings(string s) {
        ll ans = 0;
        int n = s.size();
        ans += 1LL * n * (n + 1) / 2;

        ll bad = 0;
        int prev = -1;

        for (int i = 0; i + 2 < n; i++) {
            if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
                bad += 1LL * (i + 1) * (n - i - 2);

                if (prev != -1)
                    bad -= 1LL * (prev + 1) * (n - i - 2);

                prev = i;
            }
        }

        return ans - bad;
    }
};