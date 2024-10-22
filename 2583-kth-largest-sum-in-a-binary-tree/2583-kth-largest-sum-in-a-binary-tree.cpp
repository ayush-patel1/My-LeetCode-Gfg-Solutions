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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long>pq;
        if(!root && k!=0) return -1;
        int level=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            long long level_sum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                level_sum+=curr->val;
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            pq.push(level_sum);
            level++;
        }
        if(pq.size()<k) return -1;
            while(!pq.empty() && --k){
                pq.pop();
            }
        return pq.top();
    }
};