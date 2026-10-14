class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = string(num, '9');
        int sm = 0;
        for(int i = 0; i < num; i++) sm += 9;
        if(sum > sm) return "";
        string res = "";
        while(sum && res.size() < num) {
            for(char ch = '9'; ch >= '0'; ch--) {
                if(sum >= ch - '0') {
                    res += ch;
                    sum -= (ch - '0');
                    break;
                }
            }
        }
        while(res.size() < num) res += '0';
        return res;
    }
};