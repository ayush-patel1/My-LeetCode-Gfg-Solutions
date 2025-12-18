class Solution {
public:
    vector<int> seg;
    int N;

    void update(int idx, int l, int r, int pos) {
        if(pos<l || pos>r) return ;
        if (l == r) {
            seg[idx]++;
            return;
        }
        int mid = (l + r) >> 1;
        update(2*idx+1, l, mid, pos);
        update(2*idx+2, mid+1, r, pos);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) >> 1;
        return query(2*idx+1, l, mid, ql, qr)
             + query(2*idx+2, mid+1, r, ql, qr);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> ps(n + 1, 0);

        for (int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + nums[i];

        vector<long long> all = ps;
        for (long long x : ps) {
            all.push_back(x - lower);
            all.push_back(x - upper);
        }

        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        N = all.size();
        seg.assign(4 * N, 0);

        auto id = [&](long long x) {
            return lower_bound(all.begin(), all.end(), x) - all.begin();
        };

        int ans = 0;

        update(0, 0, N-1, id(0));

        for (int i = 1; i <= n; i++) {
            int L = id(ps[i] - upper);
            int R = id(ps[i] - lower);
            ans += query(0, 0, N-1, L, R);
            update(0, 0, N-1, id(ps[i]));
        }

        return ans;
    }
};
