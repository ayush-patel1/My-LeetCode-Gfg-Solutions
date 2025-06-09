class Solution {
public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> st;
        vector<int> res;

        pq.push({A[N - 1] + B[N - 1], {N - 1, N - 1}});
        st.insert({N - 1, N - 1});

        while (!pq.empty() && K--) {
            auto top = pq.top(); pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;

            res.push_back(sum);

            if (i - 1 >= 0 && !st.count({i - 1, j})) {
                pq.push({A[i - 1] + B[j], {i - 1, j}});
                st.insert({i - 1, j});
            }
            if (j - 1 >= 0 && !st.count({i, j - 1})) {
                pq.push({A[i] + B[j - 1], {i, j - 1}});
                st.insert({i, j - 1});
            }
        }

        return res;
    }
};
