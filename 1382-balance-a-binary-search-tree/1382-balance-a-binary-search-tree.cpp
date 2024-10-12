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
    void Inorder(TreeNode* root, vector<int>& inorder) {
        if (!root) return;
        Inorder(root->left, inorder);
        inorder.push_back(root->val);
        Inorder(root->right, inorder);
    }
    
    TreeNode* solve(vector<int>& inorder, int left, int right) {
        if (left > right) return nullptr;
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = solve(inorder, left, mid - 1);
        root->right = solve(inorder, mid + 1, right);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        Inorder(root, inorder);
        return solve(inorder, 0, inorder.size() - 1);
    }
};
