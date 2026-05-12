class Solution {
public:
    
    bool check(int mid, vector<vector<int>>& t) {
        int cur = mid;
        
        for (auto &x : t) {
            int a = x[0];
            int m = x[1];
            
            if (cur < m) return false;
            
            cur -= a;
        }
        
        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) {
        int n = tasks.size();

        sort(tasks.begin(), tasks.end(), [](auto &a, auto &b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int l = 0, r = 1e9, ans = 1e9;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid, tasks)) {
                ans = mid;
                r = mid - 1;
            } 
            else {
                l = mid + 1;
            }
        }

        return ans;
    }
};