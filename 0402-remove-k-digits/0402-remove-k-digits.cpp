class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        for(int i=0; i<num.length(); ++i){
            while(ans.length()>0 && ans.back()>num[i] && k>0){
                k--;
                ans.pop_back();
            }
            if(ans.length()>0){
                ans.push_back(num[i]);
            }
            else if(num[i]!='0'){
                ans.push_back(num[i]);
            }
        }
        while(k>0 && ans.length()>0){
            ans.pop_back();
            k--;
        }
        return ans.length()>0 ? ans : "0";
    }
};