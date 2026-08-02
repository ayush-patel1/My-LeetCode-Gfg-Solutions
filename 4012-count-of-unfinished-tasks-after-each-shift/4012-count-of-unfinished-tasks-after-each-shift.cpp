class Solution {
public:
#define ll long long

    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        int n = tasks.size();

        //set off set from where to do binary search on prefix array
        //incremenet starting pt(base) to that point as left
        //subtract pre[l] from that point and look

        vector<ll> pre(n);
        pre[0] = tasks[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + tasks[i];

        ll total = pre.back();
        ll done = 0;

        vector<int> ans;

        for (int x : shifts) {
            if (done + x >= total) {
                ans.push_back(0);
                done = 0;
            } else {
                done += x;
                int idx = upper_bound(pre.begin(), pre.end(), done) - pre.begin();
                ans.push_back(n - idx);
            }
        }

        return ans;
    }
};