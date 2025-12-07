class Solution {
public:
    vector<int> isPrime;
    vector<int> primes;

    void precompute(int n) {
        isPrime.assign(n + 1, true);
        if (n >= 0) isPrime[0] = false;
        if (n >= 1) isPrime[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        primes.clear();
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
    }

    int largestPrime(int n) {
        precompute(n);
        long long s = 0;
        int ans = 0;

        for (int i = 0; i < primes.size(); i++) {
            s += primes[i];
            if (s > n) break;
            if (s <= n && isPrime[s]) ans = s;
        }

        return ans;
    }
};
