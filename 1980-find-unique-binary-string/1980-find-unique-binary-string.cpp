class Solution {
public:
    unordered_set<string> st;

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        for(auto &num: nums) st.insert(num);

        for(int i = 0; i < (1<<n); i++){
            string s="";
            for(int j = 0; j < n; j++){
                if(i & (1<<j)){
                    s+="1";
                }else s+="0";
            }
            if(st.find(s) == st.end()) return s;
        }
        return "";
    }
};