class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;

        while (!isSorted(nums)) {
            int min_sum = INT_MAX, min_idx = -1;

            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < min_sum) {
                    min_sum = sum;
                    min_idx = i;
                }
            }

            vector<int> temp;
            for (int i = 0; i < min_idx; i++) {
                temp.push_back(nums[i]);
            }

            temp.push_back(min_sum);

            for (int i = min_idx + 2; i < nums.size(); i++) {
                temp.push_back(nums[i]);
            }

            nums = temp;
            cnt++;
        }

        return cnt;
    }
};