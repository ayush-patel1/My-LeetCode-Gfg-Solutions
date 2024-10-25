class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
int n = nums.size();
vector<int> res;
unordered_map<int, int> mp;
for (int i = 0; i < k; i++) {
    mp[nums[i]]++;
}
int left = 0;
int right = k - 1;
while (right < n) {
    int curr_sum = 0;
    int temp_x = x;
    priority_queue<pair<int, int>> pq;
    for (auto it : mp) {
        pq.push({it.second, it.first});
    }
    while (!pq.empty() && temp_x--) {
        auto top = pq.top();
        pq.pop();
        curr_sum += top.second*top.first;
    }
    res.push_back(curr_sum);
    mp[nums[left]]--;
    if (mp[nums[left]] == 0) {
        mp.erase(nums[left]);
    }
    left++;
    right++;
    if (right < n) {
        mp[nums[right]]++;
    }
}
return res;

    }
};