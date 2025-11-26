class Solution {
public:
    long long sumAndMultiply(int n) {
        string s=to_string(n);
        string res=""; int sum=0;
        for(auto &ch:s){
            if(ch=='0') continue;
            res+=ch; sum+=ch-'0';
        }
        if(res.empty()) res="0";
        return 1LL*stoll(res)*sum;
    }
};