class Solution {
public:
    #define ll long long
    long long countGoodSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, -1), r(n, n);

        stack<int> st;

        for(int i = 0; i < n; i++){
            while(!st.empty() && ((nums[st.top()] | nums[i]) != nums[st.top()])){
                r[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() && (((nums[st.top()] | nums[i]) != nums[st.top()]) || nums[st.top()] == nums[i])){
                l[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll left = i - l[i];
            ll right = r[i] - i;
            ans += left * right;
        }

        return ans;
    }
};