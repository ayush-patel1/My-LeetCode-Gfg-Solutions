#define ll long long
using namespace std;

class Solution {
    ll sum = 0;
    multiset<int> sm, lg;

    void add(int x, int m) {
        sm.insert(x);
        sum += x;
        if ((int)sm.size() > m) {
            auto it = prev(sm.end());
            sum -= *it;
            lg.insert(*it);
            sm.erase(it);
        }
    }

    void remove(int x) {
        auto it = sm.find(x);
        if (it != sm.end()) {
            sum -= x;
            sm.erase(it);
            if (!lg.empty()) {
                auto it2 = lg.begin();
                sum += *it2;
                sm.insert(*it2);
                lg.erase(it2);
            }
        } else {
            lg.erase(lg.find(x));
        }
    }

public:
    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        k--;

        vector<int> win(nums.begin() + 1, nums.begin() + dist + 2);
        nth_element(win.begin(), win.begin() + k, win.end());

        sm.insert(win.begin(), win.begin() + k);
        lg.insert(win.begin() + k, win.end());
        sum = accumulate(win.begin(), win.begin() + k, 0LL);

        ll ans = nums[0] + sum;

        for (int l = 1, r = dist + 2; r < n; l++, r++) {
            remove(nums[l]);
            add(nums[r], k);
            ans = min(ans, nums[0] + sum);
        }
        return ans;
    }
};
