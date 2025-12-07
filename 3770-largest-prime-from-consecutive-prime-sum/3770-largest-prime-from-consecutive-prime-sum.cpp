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

        vector<long long> prefix(primes.size());
        if (!primes.empty()) {
            prefix[0] = primes[0];
            for (int i = 1; i < primes.size(); i++)
                prefix[i] = prefix[i - 1] + primes[i];
        }

        int idx = upper_bound(prefix.begin(), prefix.end(), n) - prefix.begin() - 1;
        if (idx < 0) return 0;

        while (idx >= 0 && (! (prefix[idx] <= n && prefix[idx] < isPrime.size() && isPrime[prefix[idx]])))
            idx--;

        if (idx < 0) return 0;
        return prefix[idx];
    }
};
