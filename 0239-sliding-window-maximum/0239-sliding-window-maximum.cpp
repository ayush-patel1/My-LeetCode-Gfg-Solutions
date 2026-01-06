class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0, l = 0;
        vector<int> res;
        deque<int> dq;

        while (r < n) {
            while (!dq.empty() && nums[dq.back()] < nums[r]) {
                dq.pop_back();
            }
            dq.push_back(r);

            while (l <= r && r - l + 1 > k) {
                if (dq.front() == l) {
                    dq.pop_front();
                }
                l++;
            }

            if (r - l + 1 == k)
                res.push_back(nums[dq.front()]);

            r++;
        }
        return res;
    }
};
