class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> num_str(nums.size());
        
        // Convert all integers to strings
        for(int i = 0; i < nums.size(); i++) {
            num_str[i] = to_string(nums[i]);
        }
        
        // Sort strings based on custom comparator
        sort(num_str.begin(), num_str.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        
        // Form the largest number by concatenating sorted strings
        string ans = "";
        for(const string& str : num_str) {
            ans += str;
        }
        
        // Handle the case where the largest number is "0" (e.g., ["0", "0"])
        if(ans[0] == '0') return "0";
        
        return ans;
    }
};
