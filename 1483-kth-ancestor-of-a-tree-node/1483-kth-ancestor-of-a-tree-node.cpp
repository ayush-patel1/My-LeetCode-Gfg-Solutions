class TreeAncestor {
public:
    const int MAX = 16;
    int n_;
    vector<vector<int>> dp;

    void fill() {
        for (int i = 1; i < MAX; i++) {
            for (int j = 0; j < n_; j++) {
                if (dp[i - 1][j] == -1) dp[i][j] = -1;
                else dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }

    int find(int k, int node) {
        for (int i = 0; i < MAX; i++) {
            if ((1 << i) & k) {
                node = dp[i][node];
                if (node == -1) break;
            }
        }
        return node;
    }

    TreeAncestor(int n, vector<int>& parent) {
        dp.assign(MAX, vector<int>(n, -1));
        n_ = n;
        for (int i = 0; i < n; i++) {
            dp[0][i] = parent[i];
        }
        fill();
    }

    int getKthAncestor(int node, int k) {
        return find(k, node);
    }
};
