class Solution {
public:
#define ll long long

    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pref(n, 0), suff(n, 0);

        pref[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                pref[i] = max(pref[i - 1] + nums[i], 1LL*nums[i]);
            else
                pref[i] = nums[i];
        }

        suff[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1])
                suff[i] = max(suff[i + 1] + nums[i], (ll)nums[i]);
            else
                suff[i] = nums[i];
        }

        ll res = -1e18;
        int i = 2;

        while (i < n - 1) {
            if (nums[i] < nums[i - 1]) {
                ll temp = nums[i - 1];
                int x = i - 2;

                while (i < n - 1 && nums[i] < nums[i - 1]) {
                    temp += nums[i];
                    i++;
                }

                if (nums[i] > nums[i - 1] && nums[x] < nums[x + 1]) {
                    res = max(res, temp + pref[x] + suff[i]);
                }
            } else {
                i++;
            }
        }

        return res;
    }
};

// what we can do is , we can find the prefix increasing subaraay which is
// giving maximum sum //similalry sufix decreasing array which is giving maximum
// sum //where the prefix is ennding be p, and similarly where suffix is ending
// left be s //then between from index s to index p must be decreasig array , we
// can't maximise it's sum //as it's not in our control it's fixed right? //we
// can maximise suffix and prefix one , as it's in our control the point from
// where to start //starting wala increasing part suffix ki help se calcualte
// kro bcz tbbhi tumhara control hoga, ki //eske aur piche bdhna ya nhi if it's
// decreasing then dont go can use kadane i guess