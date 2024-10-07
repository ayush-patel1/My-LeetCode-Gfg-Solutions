class Solution {
public:
    int minLength(string s) {
        string ans=s;
        while(ans.find("AB")!=-1 || ans.find("CD")!=-1){
            if(ans.find("AB")!=-1){
                int ind_found=ans.find("AB");
                ans=ans.substr(0,ind_found)+ans.substr(ind_found+2);
            }
            if(ans.find("CD")!=-1){
                int ind_found=ans.find("CD");
                ans=ans.substr(0,ind_found)+ans.substr(ind_found+2);
            }
        }
        return ans.size();
    }
};