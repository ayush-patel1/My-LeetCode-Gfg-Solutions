class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<int> isOp(c + 1, 1);
        DisjointSet d(c);
        for (auto c : connections) {
            int u = c[0], v = c[1];
            d.unionBySize(u, v);
        }
        unordered_map<int, priority_queue<int>> mp;
        for (int i = 1; i <= c; i++) {
            mp[d.findUPar(i)].push(-i);
        }
        vector<int> res;
        for (auto q : queries) {
            int id = q[0], x = q[1];
            if (id == 2)
                isOp[x] = 0;
            if (id == 1) {
                if (isOp[x]) {
                    res.push_back(x);
                } else {
                    auto& pq = mp[d.findUPar(x)];
                    while (!pq.empty() && !isOp[-pq.top()]) {
                        pq.pop();
                    }
                    if (!pq.empty()) {
                        res.push_back(-pq.top());
                    } else {
                        res.push_back(-1);
                    }
                }
            }
        }
        return res;
    }
};
