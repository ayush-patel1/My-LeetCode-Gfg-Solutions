class Solution {
public:
    bool check(vector<int>& coins, int k, long long x) {
        int n = coins.size();
        long long cnt = 0;

        for(int msk = 1; msk < (1 << n); msk++) {
            long long l = 1;
            int bit = 0;

            for(int i = 0; i < n; i++) {
                if(msk & (1 << i)) {
                    l = lcm(l, (long long)coins[i]);
                    bit++;

                    if(l > x)
                        break;
                }
            }

            if(l > x)
                continue;

            if(bit % 2 == 1) {
                cnt += x / l;
            }
            else {
                cnt -= x / l;
            }
        }

        return cnt >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        long long low = 1;
        long long high = 1LL * coins[0] * k;

        for(int &x : coins) {
            high = min(high, 1LL * x * k);
        }

        long long ans = high;

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(check(coins, k, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};