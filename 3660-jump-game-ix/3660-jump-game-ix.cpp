class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int findUPar(int x) {
        return x == parent[x] ? x : parent[x] = findUPar(parent[x]);
    }
    void unionBySize(int u, int v) {
        if (u == -1 || v == -1) return;
        int pu = findUPar(u), pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) parent[pu] = pv, size[pv] += size[pu];
        else parent[pv] = pu, size[pu] += size[pv];
    }
};

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n), suff(n), res(nums);
        pref[0] = nums[0];
        for (int i = 1; i < n; i++) pref[i] = max(pref[i-1], nums[i]);
        suff[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) suff[i] = min(suff[i+1], nums[i]);

        DisjointSet d(n);
        for (int i = 0; i < n-1; i++) {
            if (pref[i] > suff[i+1]) d.unionBySize(i, i+1);
        }

        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            int p = d.findUPar(i);
            mp[p] = max(mp.count(p) ? mp[p] : nums[i], nums[i]);
        }
        for (int i = 0; i < n; i++) {
            res[i] = mp[d.findUPar(i)];
        }
        return res;
    }
};
