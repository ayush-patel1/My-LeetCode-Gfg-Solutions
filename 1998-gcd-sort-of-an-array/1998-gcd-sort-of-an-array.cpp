class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    bool gcdSort(vector<int>& nums) {
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());
        DisjointSet d(mx);

        for(int i=0;i<n;i++){
            int num=nums[i];
            for(int j=2;j*j<=num;j++){
                if(num%j==0){
                    d.unionByRank(num,j);
                    if(j*j!=num)
                        d.unionByRank(num,num/j);
                }
            }
        }

        vector<int> s=nums;
        sort(s.begin(),s.end());

        for(int i=0;i<n;i++){
            if(d.findUPar(nums[i])!=d.findUPar(s[i]))
                return false;
        }

        return true;
    }
};