class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(capacity.rbegin(), capacity.rend());
        long long total = accumulate(apple.begin(), apple.end(), 0LL);
        int cnt = 0, i = 0;
        while (total > 0) {
            total -= capacity[i];
            cnt++; 
            i++;
        }
        return cnt;
    }
};
