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
    int maxLevelSum(TreeNode* root) {
        int max_sum=-1e9;
        if(!root) return 0;
        queue<TreeNode*>q;
        q.push(root);
        int level=1; int max_lev=0;
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                auto node=q.front();
                sum+=node->val;
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(sum>max_sum){
                max_lev=level;
                max_sum=sum;
            }
            level++;
        }
        return max_lev;
    }
};