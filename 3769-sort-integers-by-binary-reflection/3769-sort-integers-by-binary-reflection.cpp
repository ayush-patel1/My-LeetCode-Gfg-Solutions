class Solution {
public:
    int help(int num){
        string temp = "";
        while(num){
            temp += ('0' + (num & 1));
            num >>= 1;
        }
        int n = temp.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += (temp[i] - '0') * (1 << (n - i - 1));
        }
        return ans;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i = 0; i < n; i++){
            v[i] = {help(nums[i]), nums[i]};
        }
        sort(v.begin(), v.end());
        vector<int> res;
        for(int i = 0; i < n; i++){
            res.push_back(v[i].second);
        }
        return res;
    }
};
