class Solution {
public:
    unordered_map<long long, int> mp;
    int ans = 0;

    void solve(TreeNode* root, long long sum, int target) {
        if (!root) return;

        sum += root->val;

        if (mp.count(sum - target))
            ans += mp[sum - target];

        mp[sum]++;

        solve(root->left, sum, target);
        solve(root->right, sum, target);

        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        solve(root, 0, targetSum);
        return ans;
    }
};