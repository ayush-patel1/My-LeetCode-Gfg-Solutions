/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    using ll = long long;
    ll tot = 0, ans = 0;
    const int mod = 1e9 + 7;

    ll dfs(TreeNode* root) {
        if (!root) return 0;

        ll l = dfs(root->left);
        ll r = dfs(root->right);

        ll sub = root->val + l + r;
        ans = max(ans, sub * (tot - sub));
        return sub;
    }

    int maxProduct(TreeNode* root) {
        tot = dfs(root);
        dfs(root);
        return ans % mod;
    }
};
