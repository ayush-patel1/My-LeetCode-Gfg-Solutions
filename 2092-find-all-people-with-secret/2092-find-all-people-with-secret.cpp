class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n+1);
        size.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findUPar(int x) {
        return parent[x] == x ? x : parent[x] = findUPar(parent[x]);
    }

    void unionBySize(int u, int v) {
        u = findUPar(u);
        v = findUPar(v);
        if (u == v) return;
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        DisjointSet d(n);
        d.unionBySize(0, firstPerson);

        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int i = 0;
        while (i < meetings.size()) {
            int t = meetings[i][2];
            vector<int> touched;

            int j = i;
            while (j < meetings.size() && meetings[j][2] == t) {
                d.unionBySize(meetings[j][0], meetings[j][1]);
                touched.push_back(meetings[j][0]);
                touched.push_back(meetings[j][1]);
                j++;
            }

            for (int x : touched) {
                if (d.findUPar(x) != d.findUPar(0)) {
                    d.parent[x] = x;
                }
            }

            i = j;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (d.findUPar(i) == d.findUPar(0)) {
                res.push_back(i);
            }
        }
        return res;
    }
};
