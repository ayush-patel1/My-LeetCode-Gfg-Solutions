class Solution {
public:
bool check(int t,vector<int>&v,int d){
    int s=0;
    int days=1;
    for(auto &it:v){
        if(s+it>t){
           days++;
           s=it;
        }else s+=it;
    }
    return days<=d;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid, weights, days)) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};