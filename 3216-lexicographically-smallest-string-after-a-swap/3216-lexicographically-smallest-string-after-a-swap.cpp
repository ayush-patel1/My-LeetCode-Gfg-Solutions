class Solution {
public:
    string getSmallestString(string s) {
        // we will start in order from left to right
        // jaise hi adjcanet aise mil jaate like 35 or 57 right wala agr bda to
        // swap immediatily bcz baad mai krne se utna significant efffect nhi
        // aaygea
        int n = s.size();
        for (int i = 0; i + 1 < n; i++) {
            int d1 = s[i] - '0';
            int d2 = s[i + 1] - '0';
            if (d1 % 2 == d2 % 2 && d1 > d2) {
                swap(s[i], s[i + 1]);
                break;
            }
        }
        return s;
    }
};