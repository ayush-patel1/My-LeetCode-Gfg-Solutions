class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string>st(bannedWords.begin(),bannedWords.end());
        int n=message.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(st.find(message[i])!=st.end()){
                count++;
            }
        }
        return count>=2;
    }
};