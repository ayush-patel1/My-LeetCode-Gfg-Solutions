class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int mn = n, ops = 0;
        char f = '1';

        for(int i = 0; i < n; i++){
            if(s[i] != f) ops++;
            f = (f == '1' ? '0' : '1');
        }

        mn = min(mn, ops);
        ops = 0;
        f = '0';

        for(int i = 0; i < n; i++){
            if(s[i] != f) ops++;
            f = (f == '1' ? '0' : '1');
        }

        mn = min(mn, ops);
        return mn;
    }
};