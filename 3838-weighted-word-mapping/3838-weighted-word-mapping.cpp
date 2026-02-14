class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        int n=words.size();
        for(int i=0;i<n;i++){
            string s=words[i];
            int cnt=0;
            for(auto &ch:s){
                cnt+=weights[ch-'a'];
            }
            cnt%=26;
            ans+=char('a'+(25-cnt+26)%26);
        }
        return ans;
    }
};
