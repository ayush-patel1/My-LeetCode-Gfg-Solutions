class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> v(32, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) {
                if ((nums[i] >> j) & 1) {
                    v[j]++;
                }
            }
        }
        int highestBit = 0;
        for (int i = 0; i < 32; i++) {
            if (v[i] > 0)
                highestBit = i;
        }
        int result = 1 << (highestBit + 1);
        return result;
    }
};