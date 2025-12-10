class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int mini = complexity[0];
        int cnt_min = count(complexity.begin(), complexity.end(), mini);
        for (int i = 1; i < n; i++) if (complexity[i] <= mini) return 0;
        long long res = 1;
        for (int i = 1; i <= n - 1; i++) {
            res = (res * i) % MOD;
        }
        return res % MOD;
    }
};
