class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0; 
        
        int res = 0;
        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;

        while (left <= right) {
            if (heights[left] <= heights[right]) {
                if (heights[left] >= left_max) {
                    left_max = heights[left];
                } else {
                    res += left_max - heights[left];
                }
                left++;
            } else {
                if (heights[right] >= right_max) {
                    right_max = heights[right];
                } else {
                    res += right_max - heights[right];
                }
                right--;
            }
        }
        return res;
    }
};