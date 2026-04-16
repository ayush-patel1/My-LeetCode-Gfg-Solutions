class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res(queries.size(), -1);

        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            auto& idxs = mp[nums[q]];

            if (idxs.size() == 1) continue; 

            int pos = lower_bound(idxs.begin(), idxs.end(), q) - idxs.begin();

            if (idxs[0] == q) {
                res[i] = min(abs(idxs[1] - idxs[0]), abs(n + idxs[0] - idxs.back() ));
            } else if (idxs.back() == q) {
                res[i] = min(abs(idxs.back() - idxs[idxs.size() - 2]), abs(n + idxs[0] - idxs.back() ));
            } else {
                res[i] = min(abs(idxs[pos] - idxs[pos - 1]), abs(idxs[pos + 1] - idxs[pos]));
            }
        }
        
        return res;
    }
};