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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(!root) return root;
        int level=0;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>level_sum;
        while(!q.empty()){
            int size=q.size();
            int curr_sum=0;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    curr_sum+=node->left->val;
                    q.push(node->left);
                }
                if(node->right){
                    curr_sum+=node->right->val;
                    q.push(node->right);
                }
            }
            level_sum.push_back(curr_sum);
            level++;
        }
        
        level=0;
        q.push(root);
        root->val=0;
        while(!q.empty()){
           int size=q.size();
            for(int i=0;i<size;i++){
            int sum=0;
            TreeNode* node=q.front();
            q.pop();
            if(node->left) sum+=node->left->val;
            if(node->right) sum+=node->right->val;
            if(node->left){
                 node->left->val=level_sum[level]-sum;
                q.push(node->left);
            }
            if(node->right){
                 node->right->val=level_sum[level]-sum;
                q.push(node->right);
            }
            }
            level++;
            
        }
        return root;
    }
};