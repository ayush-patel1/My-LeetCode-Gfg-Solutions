class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int>st;
        for(int i=0;i*i<=1e9;i++){
            st.insert(i*i);
        }
        int i=0;
        while(1LL*i*i<=c){
            if(st.find(c-i*i)!=st.end()) return true;
            i++;
        }
        return false;
    }
};