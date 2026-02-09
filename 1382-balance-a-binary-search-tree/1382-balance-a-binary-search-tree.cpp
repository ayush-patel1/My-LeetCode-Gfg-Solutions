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
    void Inorder(vector<int>& a, TreeNode* r){
        if(!r) return;
        Inorder(a,r->left);
        a.push_back(r->val);
        Inorder(a,r->right);
    }

    TreeNode* solve(vector<int>& a,int l,int r){
        if(l>r) return NULL;
        int m=(l+r)/2;
        TreeNode* root=new TreeNode(a[m]);
        root->left=solve(a,l,m-1);
        root->right=solve(a,m+1,r);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> a;
        Inorder(a,root);
        return solve(a,0,a.size()-1);
    }
};
