class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int r_sum = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            r_sum += arr[i];
            if (mp.find(r_sum - target) != mp.end()) {
                return {mp[r_sum - target] + 2, i + 1};
            }
            if (mp.find(r_sum) == mp.end()) {
                mp[r_sum] = i;
            }
        }
        return {-1};
    }
};
