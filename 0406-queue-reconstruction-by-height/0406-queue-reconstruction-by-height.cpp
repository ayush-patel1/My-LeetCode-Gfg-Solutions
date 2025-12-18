class Solution {
public:
    vector<int> seg;
    int n;

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    int kthEmpty(int idx, int l, int r, int k) {
        if (l == r) return l;
        int mid = (l + r) >> 1;
        if (seg[2*idx+1] >= k)
            return kthEmpty(2*idx+1, l, mid, k);
        else
            return kthEmpty(2*idx+2, mid+1, r, k - seg[2*idx+1]);
    }

    void update(int idx, int l, int r, int pos) {
        if (l == r) {
            seg[idx] = 0;
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(2*idx+1, l, mid, pos);
        else update(2*idx+2, mid+1, r, pos);
        seg[idx] = seg[2*idx+1] + seg[2*idx+2];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        n = people.size();
        seg.assign(4*n, 0);

        sort(people.begin(), people.end(), [](auto &a, auto &b) {
            if (a[0] != b[0]) return a[0] < b[0]; 
            return a[1] > b[1];                  
        });

        build(0, 0, n-1);

        vector<vector<int>> ans(n);
        for (auto &p : people) {
            int pos = kthEmpty(0, 0, n-1, p[1] + 1);
            ans[pos] = p;
            update(0, 0, n-1, pos);
        }
        return ans;
    }
};
