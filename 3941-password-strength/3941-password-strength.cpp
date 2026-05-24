class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char>st;
        int score=0;
        for(auto &ch:password){
            if(st.find(ch)!=st.end()) continue;
            else if(ch>='a' && ch<='z') score+=1;
            else if(ch>='A' && ch<='Z') score+=2;
            else if(ch>='0' && ch<='9') score+=3;
            else score+=5;
            st.insert(ch);
        }
        return score;
    }
};