class RangeFreqQuery {
    int n;
    vector<unordered_map<int,int>> st;

    void build(vector<int>& arr, int node, int l, int r) {
        if (l == r) {
            st[node][arr[l]] = 1;
            return;
        }

        int mid = (l + r) / 2;
        build(arr, 2*node+1, l, mid);
        build(arr, 2*node+2, mid+1, r);

        for (auto &p : st[2*node+1])
            st[node][p.first] += p.second;

        for (auto &p : st[2*node+2])
            st[node][p.first] += p.second;
    }

    int queryUtil(int node, int l, int r, int ql, int qr, int val) {
        if (qr < l || r < ql) return 0;

        if (ql <= l && r <= qr) {
            return st[node].count(val) ? st[node][val] : 0;
        }

        int mid = (l + r) / 2;
        return queryUtil(2*node+1, l, mid, ql, qr, val) +
               queryUtil(2*node+2, mid+1, r, ql, qr, val);
    }

public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        st.resize(4*n);
        build(arr, 0, 0, n-1);
    }

    int query(int left, int right, int value) {
        return queryUtil(0, 0, n-1, left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */