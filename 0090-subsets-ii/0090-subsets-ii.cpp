class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int pos = (1 << n);
        vector<vector<int>> res;
        set<vector<int>> st;

        for (int i = 0; i < pos; i++) {
            vector<int> temp;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    temp.push_back(nums[j]);
                }
            }
            st.insert(temp);
        }

        for (auto &it : st) res.push_back(it);
        return res;
    }
};