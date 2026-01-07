class Solution {
public:
    unordered_map<int,long long> mp;
    long long max_pr = 0;
    int tot = 0;
    vector<vector<int>> adj;

    int dfs(int node, int par) {
        long long score = 1;
        int cnt = 0;

        for (auto &it : adj[node]) {
            if (it == par) continue;
            int sub = dfs(it, node);
            score *= sub;
            cnt += sub;
        }

        int rem = tot - cnt - 1;
        if (rem > 0) score *= rem;

        max_pr = max(max_pr, score);
        mp[node] = score;

        return cnt + 1;
    }

    int countHighestScoreNodes(vector<int>& parents) {
        int n = parents.size();
        tot = n;

        adj.resize(n);
        for (int i = 1; i < n; i++) {
            adj[parents[i]].push_back(i);
            adj[i].push_back(parents[i]);
        }

        dfs(0, -1);

        int cnt = 0;
        for (auto &it : mp) {
            if (it.second == max_pr) cnt++;
        }
        return cnt;
    }
};
