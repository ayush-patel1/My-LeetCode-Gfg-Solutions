class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        DisjointSet ds(n);

        map<int, vector<int>> mx, my;

        for(int i = 0; i < n; i++){
            mx[points[i][0]].push_back(i);
            my[points[i][1]].push_back(i);
        }

        for(auto &it : mx){
            auto &v = it.second;
            for(int i = 1; i < v.size(); i++)
                ds.unionByRank(v[0], v[i]);
        }

        for(auto &it : my){
            auto &v = it.second;
            for(int i = 1; i < v.size(); i++)
                ds.unionByRank(v[0], v[i]);
        }

        vector<int> cnt(n,0);

        for(int i=0;i<n;i++){
            cnt[ds.findUPar(i)]++;
        }

        sort(cnt.begin(),cnt.end());

        if(cnt.back()==n) return n+1;

        return cnt.back()+cnt[n-2]+1;
    }
};