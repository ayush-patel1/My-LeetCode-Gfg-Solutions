class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        vector<int> preG(n, 1);
        vector<int> preL(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                preG[i] = preL[i - 1] + 1;
            } else if (nums[i] < nums[i - 1]) {
                preL[i] = preG[i - 1] + 1;
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, max(preG[i], preL[i]));
        }

        vector<int> sufG(n, 1);
        vector<int> sufL(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                sufG[i] = sufL[i + 1] + 1;
            } else if (nums[i] < nums[i + 1]) {
                sufL[i] = sufG[i + 1] + 1;
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (nums[i - 1] < nums[i + 1]) {
                ans = max(ans, preL[i - 1] + sufG[i + 1]);
            } else if (nums[i - 1] > nums[i + 1]) {
                ans = max(ans, preG[i - 1] + sufL[i + 1]);
            }
        }

        return ans;
    }
};
