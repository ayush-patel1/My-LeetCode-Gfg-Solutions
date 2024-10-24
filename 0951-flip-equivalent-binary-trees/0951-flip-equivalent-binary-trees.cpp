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
    
    bool solve(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) 
            return true;
        if((!root1 && root2 ) || (root1 && !root2))
            return false;
         if(root1->val!=root2->val) return false;
         bool flip=solve(root1->left,root2->left) && solve(root1->right,root2->right);
        bool notFlip=solve(root1->left,root2->right) && solve(root1->right,root2->left);
        return flip || notFlip;

    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
      bool res=solve(root1,root2);
        return res;
    }
};