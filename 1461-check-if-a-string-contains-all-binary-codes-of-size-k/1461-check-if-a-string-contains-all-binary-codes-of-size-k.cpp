class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //what we can do is we can store in a set all
        //binary string of length k present in s
        unordered_set<string>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            string tmp="";
            for(int j=i;j<min(i+k,n);j++){
              tmp+=s[j];
            }
            st.insert(tmp);
        }
        for(int i=0;i<(2<<k);i++){
            string tmp="";
          for(int j=0;j<k;j++){
            if(i&(1<<j)){
                tmp+='1';
            }else tmp+='0';
          }
          if(st.find(tmp)==st.end()){
            return false;
          }
        }
        return true;
    }
};