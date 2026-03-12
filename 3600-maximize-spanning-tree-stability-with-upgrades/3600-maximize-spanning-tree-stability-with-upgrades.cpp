class Solution {
public:
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

    bool check(int cost, vector<vector<int>>& edges, int k, int n) {
        DisjointSet ds(n);
        int comp = n;

        for (auto &e : edges) {
            int u=e[0],v=e[1],w=e[2],must=e[3];

            if (must==1) {
                if (w < cost) return false;

                if (ds.findUPar(u)==ds.findUPar(v)) return false;

                ds.unionByRank(u,v);
                comp--;
            }
        }

        for (auto &e : edges) {
            int u=e[0],v=e[1],w=e[2],must=e[3];

            if (must==0 && w>=cost) {
                if (ds.findUPar(u)!=ds.findUPar(v)) {
                    ds.unionByRank(u,v);
                    comp--;
                }
            }
        }

        int used=0;

        for (auto &e : edges) {
            int u=e[0],v=e[1],w=e[2],must=e[3];

            if (must==0 && w<cost && 2*w>=cost) {
                if (ds.findUPar(u)!=ds.findUPar(v)) {
                    ds.unionByRank(u,v);
                    comp--;
                    used++;
                    if (used>k) return false;
                }
            }
        }

        return comp==1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        {
            DisjointSet ds(n);
            for(auto &e:edges){
                if(e[3]==1){
                    if(ds.findUPar(e[0])==ds.findUPar(e[1])) return -1;
                    ds.unionByRank(e[0],e[1]);
                }
            }
        }

        int l=1,r=200000;
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(check(mid,edges,k,n)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }

        return ans;
    }
};