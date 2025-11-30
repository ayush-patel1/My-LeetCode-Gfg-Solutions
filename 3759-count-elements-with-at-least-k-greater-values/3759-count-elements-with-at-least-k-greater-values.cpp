class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        unordered_map<int,int> seenFreq;
        int seen = 0;

        if (k == 0) return n;

        for (int i = n - 1; i >= 0; i--) {
            int x = nums[i];
            int greater = seen - seenFreq[x];
            if (greater >= k)
                return i + 1;
            seenFreq[x]++;
            seen++;
        }

        return 0;
    }
};
