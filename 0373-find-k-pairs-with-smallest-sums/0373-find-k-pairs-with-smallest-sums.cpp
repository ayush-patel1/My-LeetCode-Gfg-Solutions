class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        for (int i = 0; i < n; i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> ans;

        while (!pq.empty() && k--) {
            auto it = pq.top();
            pq.pop();

            int x = it.second.first;
            int y = it.second.second;

            ans.push_back({nums1[x], nums2[y]});

            if (y + 1 < m) {
                pq.push({nums1[x] + nums2[y + 1], {x, y + 1}});
            }
        }

        return ans;
    }
};
