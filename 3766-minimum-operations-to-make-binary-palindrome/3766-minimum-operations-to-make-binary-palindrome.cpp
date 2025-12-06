class Solution {
public:
    vector<int> isPal = vector<int>(50001, 0);

    bool isPalindrome(string s){
        int l = 0, r = s.size() - 1;
        while(l <= r){
            if(s[l] != s[r]) return false;
            l++; 
            r--;
        }
        return true;
    }

    string toBinary(int x){
        string s = "";
        while(x){
            s += char('0' + (x & 1));
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    void precompute(){
        for(int i = 1; i <= 50000; i++){
            string s = toBinary(i);
            isPal[i] = isPalindrome(s);
        }
    }

    vector<int> minOperations(vector<int>& nums) {
        static bool done = false; //does anyone knew this thing for optimization
        static vector<int> v;

        if(!done){
            precompute();
            for(int i = 1; i <= 50000; i++){
                if(isPal[i]) v.push_back(i);
            }
            done = true;
        }

        vector<int> ans(nums.size());
        
        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            int idx = lower_bound(v.begin(), v.end(), x) - v.begin();
            
            int best = 1e9;

            if(idx > 0) best = min(best, x - v[idx-1]);
            if(idx < v.size()) best = min(best, v[idx] - x);

            ans[i] = best;
        }

        return ans;
    }
};
