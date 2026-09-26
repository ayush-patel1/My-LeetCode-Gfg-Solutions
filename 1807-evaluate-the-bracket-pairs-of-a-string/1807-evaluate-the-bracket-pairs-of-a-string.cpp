class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto &k:knowledge){
            mp[k[0]]=k[1];
        }
        bool flg=false;
        string ans="";
        string temp="";
        for(auto &ch:s){
            if(ch==')'){
                if(mp.count(temp)){
                    ans+=mp[temp];
                }else{
                    ans+='?';        
                }
                temp="";
                flg=false;
                continue;
            }
            if(flg){
               temp+=ch;
               continue;
            }
            if(ch=='('){
                 flg=true;
                 continue;
            }
            ans+=ch;
        }
        return ans;
    }
};