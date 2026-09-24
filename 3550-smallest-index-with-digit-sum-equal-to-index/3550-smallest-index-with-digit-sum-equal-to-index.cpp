class Solution {
public:
    int sum(string& s) {
        int sm = 0;
        for (auto& ch : s) {
            sm += ch - '0';
        }
        return sm;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);

            if (sum(s) == i) {
                return i;
            }
        }

        return -1;
    }
};
