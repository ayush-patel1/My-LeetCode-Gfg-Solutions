class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i], i};
        }
        
        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        
        int max_width = 0;
        int min_index = arr[0].second;
        
        for (int i = 1; i < n; i++) {
            max_width = max(max_width, arr[i].second - min_index);
            min_index = min(min_index, arr[i].second);
        }
        
        return max_width;
    }
};
