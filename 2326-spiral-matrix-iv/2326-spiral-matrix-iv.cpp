class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1)); // Fixed dimensions to m rows and n columns
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        ListNode* ptr = head;
        
        while (top <= bottom && left <= right && ptr) {
            // Fill the top row
            for (int i = left; i <= right; i++) {
                if (ptr) {
                    ans[top][i] = ptr->val;
                    ptr = ptr->next;
                }
            }
            top++;
            
            // Fill the right column
            for (int i = top; i <= bottom; i++) {
                if (ptr) {
                    ans[i][right] = ptr->val;
                    ptr = ptr->next;
                }
            }
            right--;
            
            // Fill the bottom row if there are rows left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    if (ptr) {
                        ans[bottom][i] = ptr->val;
                        ptr = ptr->next;
                    }
                }
                bottom--;
            }
            
            // Fill the left column if there are columns left
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    if (ptr) {
                        ans[i][left] = ptr->val;
                        ptr = ptr->next;
                    }
                }
                left++;
            }
        }
        
        return ans;
    }
};
