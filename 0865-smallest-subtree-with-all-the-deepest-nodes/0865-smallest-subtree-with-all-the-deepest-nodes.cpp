class Solution {
public:
    unordered_map<TreeNode*, int> mp;
    TreeNode* ans = NULL;

    void h(TreeNode* root, int d) {
        if (!root)
            return;
        mp[root] = d;
        h(root->left, d + 1);
        h(root->right, d + 1);
    }

    int solve(TreeNode* root, int cnt, int mx_d) {
        if (!root)
            return 0;

        int curr = (mp[root] == mx_d);
        int cnt_l = solve(root->left, cnt, mx_d);
        int cnt_r = solve(root->right, cnt, mx_d);

        if (curr + cnt_l + cnt_r == cnt && ans == NULL) {
            ans = root;
        }
        return curr + cnt_l + cnt_r;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        h(root, 0);

        int mx_d = 0, cnt = 0;
        for (auto& it : mp) {
            mx_d = max(mx_d, it.second);
        }
        for (auto& it : mp) {
            if (it.second == mx_d)
                cnt++;
        }

        solve(root, cnt, mx_d);
        return ans;
    }
};
