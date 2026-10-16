class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;

    struct node {
        ll sumfirst = 0, sumsecond = 0, lazy = 0;
    };

    vector<node> t;
    int n;

    void push(int id, int l, int r) {
        if (t[id].lazy) {
            ll v = t[id].lazy;
            ll len = r - l + 1;

            t[id].sumsecond = (t[id].sumsecond
                + 2 * v % mod * t[id].sumfirst % mod
                + v * v % mod * len) % mod;

            t[id].sumfirst = (t[id].sumfirst + v * len) % mod;

            if (l != r) {
                t[2 * id + 1].lazy =
                    (t[2 * id + 1].lazy + v) % mod;
                t[2 * id + 2].lazy =
                    (t[2 * id + 2].lazy + v) % mod;
            }

            t[id].lazy = 0;
        }
    }

    node merge(node a, node b) {
        node ans;
        ans.sumfirst = (a.sumfirst + b.sumfirst) % mod;
        ans.sumsecond = (a.sumsecond + b.sumsecond) % mod;
        ans.lazy = 0;
        return ans;
    }

    void update(int id, int l, int r, int ql, int qr) {
        push(id, l, r);

        if (l > qr || r < ql) return;

        if (ql <= l && r <= qr) {
            t[id].lazy = (t[id].lazy + 1) % mod;
            push(id, l, r);
            return;
        }

        int m = (l + r) / 2;

        update(2 * id + 1, l, m, ql, qr);
        update(2 * id + 2, m + 1, r, ql, qr);

        node ans = merge(t[2 * id + 1], t[2 * id + 2]);
        t[id].sumfirst = ans.sumfirst;
        t[id].sumsecond = ans.sumsecond;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        t.assign(4 * n + 5, node());

        vector<int> last(100001, -1);
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            update(0, 0, n - 1, last[nums[i]] + 1, i);
            last[nums[i]] = i;
            ans = (ans + t[0].sumsecond) % mod;
        }

        return ans;
    }
};